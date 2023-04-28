#ifndef CONCURRENCY_HPP
#define CONCURRENCY_HPP

#include "Job.hpp"
#include "csvSplitter.hpp"
#include "MapReduceEngine.hpp"

#include <thread>
#include <vector>
#include <iostream>

struct outputs : std::vector<std::vector<std::pair<std::string, int>>> {
    outputs() : std::vector<std::vector<std::pair<std::string, int>>>() {}
    void new_member (std::vector<std::pair<std::string, int>> n) { push_back(n); }
};

class Concurrency{
    private:
        int mapThreadCount;
        int redThreadCount;
    public:
        Concurrency(){mapThreadCount = 2; redThreadCount = 1;};
        Concurrency(Job config);
        int getmappers(){return mapThreadCount;};
        void runMapReduce(IMapReduce userMapReduce, std::vector<std::vector<std::string>> splitData);
};

Concurrency::Concurrency(Job config){
    mapThreadCount = config.getMappers();
    redThreadCount = config.getReducers();
}

void Concurrency::runMapReduce(IMapReduce userMapReduce, std::vector<std::vector<std::string>> splitData){;
    MapReduceEngine map_reducer_engine(userMapReduce);
    outputs mapper_outputs;

    //Create mapper threads by loop
    //run mappers concurrently
    std::vector<std::thread> mappers;
    for(int i = 0; i < mapThreadCount; ++i){
        mappers.push_back(std::thread(&outputs::new_member, std::ref(mapper_outputs), map_reducer_engine.Run(splitData[i])));
    }

    //close threads?
    for (auto& th : mappers) th.join();

    //shuffle completed maps

    //create reducer threads by loop
    //run reducers concurrently
    std::vector<std::thread> reducers;
    /*
    for(int i = 0; i < redThreadCount; ++i){
        reducers.push_back(std::thread());
    */

    //close threads
    for (auto& th : reducers) th.join();

    //combine into final return of some sort?

}

#endif //CONCURRENCY_HPP