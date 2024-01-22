//
// Created by Jakub on 20.01.2024.
//

#include "Menu.h"
//
// Created by playfulCloud on 12/27/23.
//
#include "Menu.h"
#include <iostream>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <vector>
#include "Menu.h"
#include "../Reader/FileReader.h"



void Menu::displayMenu() {
    std::cout << "=========================== Effective algorithm design 2 ===========================" << std::endl;
    int gate = 0;

    while (gate != 4) {
        std::cout << "Choose what do you want to do: " << std::endl;
        std::cout << "1 - Read data from ATSP File" << std::endl;
        std::cout << "2 - Choose algorithm with read data" << std::endl;
        std::cout << "3 - Tests" << std::endl;
        std::cout << "4 - Exit" << std::endl;
        std::cin >> gate;
        switch (gate) {
            case 1:
                graph = fileReader->readFromFile();
                break;
            case 2:
                displayAlgorithms(graph);
                break;
            case 3:

                break;
        }
    }
}


void Menu::displayAlgorithms(std::vector<std::vector<int>> graph) {
    std::cout << "=========================== Algorithms menu ===========================" << std::endl;
    int gate = 0;
    while (gate != 5) {
        std::cout << "Choose what do you want to do: " << std::endl;
        std::cout << "1 - Ant Colony algorithm " << std::endl;
        std::cout << "6 - Exit" << std::endl;
        std::cin >> gate;
        switch (gate) {
            case 1:
                colony = new Colony(2,0.0005,graph,0.8);
                colony->findFood(240,1);
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
        }
    }
}





//void Menu::doTests(std::vector<std::vector<int>> cites, int sizeOfPopulation, int crossOverType,int mutationType,int time,double crossOverChance,double mutationChance) {
//    for (int i = 0; i < 10; i++) {
//        population = new Population(cites,sizeOfPopulation,crossOverType,mutationType,time,crossOverChance,mutationChance,false,2,200);
//        population->populate();
//        population->geneticAlgorithm();
//        delete population;
//    }
//}
//
//void Menu::writeTittleToFile(std::string filename,std::vector<std::vector<int>> cites, int sizeOfPopulation, int crossOverType,int mutationType,int time,double crossOverChance,double mutationChance) {
//    std::filesystem::path projectPath = std::filesystem::current_path();
//    projectPath = projectPath.parent_path(); // Uzyskanie ścieżki do katalogu nadrzędnego
//    std::string filePath = projectPath.string() + "\\PEA_3\\Data\\" + filename;
//    std::ofstream fileStream(filePath, std::ios::app); // Open in append mode
//    std::string mutation;
//    std::string crossover;
//    switch (mutationType) {
//        case 1:
//            mutation = "SWAP";
//            break;
//        case 2:
//            mutation = "SCRUMBLE";
//            break;
//    }
//    switch (crossOverType) {
//        case 1:
//            crossover = "SINGLE-POINT";
//            break;
//        case 2:
//            crossover = "OX";
//            break;
//    }
//    fileStream << "############## Population: " << sizeOfPopulation <<" with number of cities "<< cites[0].size() <<" ############ Crossover: " << crossover << " with chance: " << crossOverChance << "Mutation: "
//               << mutation << " with chance: " << mutationChance << " ############ \n";
//
//}