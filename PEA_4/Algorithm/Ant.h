//
// Created by Jakub on 20.01.2024.
//

#ifndef PEA_4_ANT_H
#define PEA_4_ANT_H


#include <vector>

class Ant {
public:
    Ant(int startingCity);
    std::vector<int> visited;
    int startingCity;
    int pathValue;
    std::vector<int> path;

    bool contains(int element);

    void displayPath();
};


#endif //PEA_4_ANT_H
