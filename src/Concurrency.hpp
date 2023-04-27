#ifndef CONCURRENCY_HPP
#define CONCURRENCY_HPP

#include "Job.hpp"
//#include "csvSplitter.hpp"
#include "MapReduceEngine.hpp"
//#include "Shuffler.hpp"
//#include "Reducer.hpp"

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
        Concurrency(){mapThreadCount = 8; redThreadCount = 8;};
        Concurrency(Job config);
        int getmappers(){return mapThreadCount;};
        void runMapReduce(IMapReduce userMapReduce, std::vector<std::string> splitData);
};

Concurrency::Concurrency(Job config){
    mapThreadCount = config.getMappers();
    redThreadCount = config.getReducers();
}

void Concurrency::runMapReduce(IMapReduce userMapReduce, std::vector<std::string> splitData){
    IMapReduce map_reducer = userMapReduce;
    MapReduceEngine map_reducer_engine(map_reducer);
    outputs mapper_outputs;

    //Create mapper threads by loop
    //run mappers concurrently
    std::vector<std::thread> mappers;
    for(int i = 0; i < mapThreadCount; ++i){
        mappers.push_back(std::thread(&outputs::new_member, std::ref(mapper_outputs), map_reducer_engine.Run(splitData)));
    }

    //close threads?
    for (auto& th : mappers) th.join();

    //shuffle completed maps

    //create reducer threads by loop
    //run reducers concurrently
    /*
    std::vector<std::thread> reducers;
    for(int i = 0; i < redThreadCount; ++i){

    }
    */

    //close threads
    //for (auto& th : reducers) th.join();

    //combine into final return of some sort?

}

#endif //CONCURRENCY_HPP

int main(){
    Job config;
    Concurrency my_conc(config);

    std::cout << my_conc.getmappers();

    return 0;
}