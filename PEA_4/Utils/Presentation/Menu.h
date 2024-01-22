//
// Created by Jakub on 20.01.2024.
//

#ifndef PEA_4_MENU_H
#define PEA_4_MENU_H


#include <vector>
#include "../Reader/FileReader.h"
#include "../../Algorithm/Colony.h"

class Menu {

    FileReader *fileReader;
    std::vector<std::vector<int>> graph;
    void displayAlgorithms(std::vector<std::vector<int>> graph);
    Colony *colony;

public:
    void displayMenu();
};


#endif //PEA_4_MENU_H
