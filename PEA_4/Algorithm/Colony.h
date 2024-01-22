//
// Created by Jakub on 21.01.2024.
//

#ifndef PEA_4_COLONY_H
#define PEA_4_COLONY_H


#include "Ant.h"

class Colony {
public:
    double alpha;
    double beta;
    std::vector<std::vector<int>>cities;
    std::vector<Ant>ants;
    int numberOfCities;
    std::vector<std::vector<double>>pheromones;
    void findFood(int time, int pheromoneScheme);
    Colony(double alpha, double beta,std::vector<std::vector<int>>cities,double evaporationRate);
    void populateColony();
    double calculateProbability(int currentCity, int nextCity, Ant currentAnt);
    int selectNextCity(const std::vector<double> &probabilities);
    void addCityToAntsPath(Ant& currentAnt);
    double evaporationRate;
    void createPathForEachAnt();


    void updatePheromones();

    int calculatePathCost(std::vector<int> path, std::vector<std::vector<int>> matrix);

    void sortTheColony();

    void updatePheromones(Ant &ant);
};


#endif //PEA_4_COLONY_H
