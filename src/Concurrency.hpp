#ifndef CONCURRENCY_HPP
#define CONCURRENCY_HPP

#include "Job.hpp"
#include "csvSplitter.hpp"
#include "MapReduceEngine.hpp"

#include <chrono>
#include <thread>
#include <vector>
#include <map>
#include <iostream>

struct outputs : std::vector<std::pair<std::string, int>> {
    outputs() : std::vector<std::pair<std::string, int>>() {}
    //combines map returns
    void new_member (std::vector<std::pair<std::string, int>> n) {
        insert(end(), std::make_move_iterator(n.begin()), std::make_move_iterator(n.end()));
    }
};

struct reducerOutputs : std::map<std::string, int> {
    reducerOutputs() : std::map<std::string, int>() {}
    //combines reduce returns
    void new_member (std::map<std::string, int> n) { merge(n); }
};

class Concurrency{
    private:
        int mapThreadCount;
        int redThreadCount;
    public:
        Concurrency(){mapThreadCount = 4; redThreadCount = 4;};
        Concurrency(Job config);
        std::map<std::string, int> runMapReduce(IMapReduce& userMapReduce, const std::vector<std::string>& inputFiles);
};

Concurrency::Concurrency(Job config){
    mapThreadCount = config.getMappers();
    redThreadCount = config.getReducers();
}

std::map<std::string, int> Concurrency::runMapReduce(
    IMapReduce& userMapReduce,
    const std::vector<std::string>& inputFiles
) {


    MapReduceEngine map_reducer_engine(userMapReduce);
    csvSplitter splitter(mapThreadCount, redThreadCount);
    outputs mapper_outputs;
    reducerOutputs reducer_outputs;

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    //Split inputData for mappers
    std::vector<std::vector<std::string>> splitData = splitter.splitCsv(inputFiles);

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

    //Create mapper threads by loop
    //run mappers concurrently
    std::vector<std::thread> mappers;
    for(int i = 0; i < mapThreadCount; ++i){
        mappers.push_back(std::thread(&outputs::new_member, std::ref(mapper_outputs), map_reducer_engine.Map(splitData[i])));
    }

    //std::this_thread::sleep_for(std::chrono::seconds(2));

    //close threads
    for (auto& th : mappers) th.join();

    //shuffle completed maps
    //and split up for reducers
    std::vector<std::map<std::string, std::vector<int>>> splitMaps = splitter.splitMap(map_reducer_engine.Shuffle(mapper_outputs));

    //create reducer threads by loop
    //run reducers concurrently
    std::vector<std::thread> reducers;
    for(int i = 0; i < redThreadCount; ++i){
        reducers.push_back(std::thread(&reducerOutputs::new_member, std::ref(reducer_outputs), map_reducer_engine.Reduce(splitMaps[i])));
    }

    /*
     * Quick and dirty hotfix for segmentation fault issues.
     */
    //std::this_thread::sleep_for(std::chrono::seconds(2));

    //close threads
    for (auto& th : reducers) th.join();

    //return combined resulting map
    return reducer_outputs;
}

#endif //CONCURRENCY_HPP