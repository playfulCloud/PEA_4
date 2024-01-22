//
// Created by Jakub on 20.01.2024.
//

#include <algorithm>
#include <iostream>
#include "Ant.h"

Ant::Ant(int startingCity) {
    this->startingCity = startingCity;
    this->path.push_back(startingCity);
    this->visited.push_back(startingCity);
}


bool Ant::contains(int element) {
    return std::find(visited.begin(), visited.end(), element) == visited.end();
}


void Ant::displayPath(){
    std::cout << "Path: ";
    for(int i = 0; i < visited.size(); i++){
        std::cout << visited[i] << " ";
    }
    std::cout << std::endl;
}