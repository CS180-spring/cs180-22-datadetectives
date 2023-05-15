#ifndef CRV_SPLITTER_H
#define CRV_SPLITTER_H

#include <vector>
#include <string>
#include <map>
#include <iostream>

class csvSplitter
{
public:
    csvSplitter(int mapThreads, int redThreads) : threadCount(mapThreads), redThreadCount(redThreads){};
    std::vector<std::vector<std::string>> splitCsv(std::vector<std::string> csvFile);
    std::vector<std::map<std::string, std::vector<int>>> splitMap(std::map<std::string, std::vector<int>> mappedData);

private:
    int threadCount;
    int redThreadCount;
};

std::vector<std::vector<std::string>> csvSplitter::splitCsv(std::vector<std::string> csvFile) {
    std::vector<std::vector<std::string>> vect;

    // Checking for an empty input file/vector
    if (csvFile.size() == 0)
    {
        std::cout << "ERROR: _EMPTY_ARGUMENT" << std::endl;
        return vect;
    }

    // creates "equal" sized subvectors depending on # of threads in use
    int intervals = 0;
    int i = 0;
    while(true)
    {
        // last thread would handle lines(modulos threadCount) extra
        if (intervals >= threadCount - 1)
        {
            vect.push_back(std::vector<std::string>(csvFile.begin() + i, csvFile.end()));
            break;
        }
        vect.push_back(std::vector<std::string>(csvFile.begin() + i, csvFile.begin() + i + int(csvFile.size() / threadCount)));

        i += int(csvFile.size() / threadCount);
        intervals++;
    }

    return vect;
}

std::vector<std::map<std::string, std::vector<int>>> csvSplitter::splitMap(std::map<std::string, std::vector<int>> mappedData) {
    std::vector<std::map<std::string, std::vector<int>>> splitData;
    int count = 0;

    std::map<std::string, std::vector<int>>::iterator it = mappedData.begin();
    int i = int(mappedData.size() / redThreadCount);
    while (true)
    {
        if (count >= redThreadCount - 1)
        {
            splitData.push_back(std::map<std::string, std::vector<int>>(it, mappedData.end()));
            break;
        }
        splitData.push_back(std::map<std::string, std::vector<int>>(it, std::next(it, i)));

        it = std::next(it, i);
        count++;
    }

    return splitData;
}

#endif // CRV_SPLITTER_H