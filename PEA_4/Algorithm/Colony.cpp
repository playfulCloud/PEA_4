//
// Created by Jakub on 21.01.2024.
//

#include <chrono>
#include <vector>
#include <valarray>
#include <numeric>
#include <iostream>
#include "Colony.h"

Colony::Colony(double alpha, double beta, std::vector<std::vector<int>>cities, double evaporationRate){
    this->alpha = alpha;
    this->beta = beta;
    this->cities = cities;
    this->numberOfCities = cities[0].size();
    this->pheromones = std::vector<std::vector<double>>(numberOfCities, std::vector<double>(numberOfCities, 0.1));
    this->evaporationRate = evaporationRate;
}

void Colony::findFood(int time,int pheromoneScheme) {

    std::vector<Ant> bests;
    auto startTime = std::chrono::high_resolution_clock::now();

    while(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - startTime).count() < time * 1000){

        populateColony();
        createPathForEachAnt();
        for (int i = 0; i < numberOfCities; ++i) {
            for (int j = 0; j < numberOfCities; ++j) {
                pheromones[i][j] *= (1 - evaporationRate); // evaporationRate to współczynnik parowania
            }
        }

        sortTheColony();
        bests.push_back(ants[0]);
        ants.clear();

    }
    for(int i = 0; i < bests.size(); i++){
        std::cout << "Best: " << bests[i].pathValue << std::endl;
    }

}

void Colony::populateColony(){
    for(int i = 0; i < numberOfCities; i++){
        Ant antToAdd = *new Ant(i);
        ants.push_back(antToAdd);
    }
}

void Colony::createPathForEachAnt(){
    // dla każdej mrówki
    for(int i = 0; i < ants.size(); i++){
        for(int j = 0; j < numberOfCities-2; j++){
            addCityToAntsPath(ants[i]);
        }

        ants[i].visited.push_back(ants[i].startingCity);
        ants[i].pathValue = calculatePathCost(ants[i].visited,cities);
    }
}


double Colony::calculateProbability(int currentCity, int nextCity, Ant currentAnt) {

    double pheromone = pow(this->pheromones[currentCity][nextCity],alpha);
    double heuristicValue = pow(cities[currentCity][nextCity], beta);
    double sum = 0.0;

    // Suma po wszystkich dostępnych krawędziach
    for (int i = 0; i < pheromones.size(); ++i) {
        double pheromone_i = pow(this->pheromones[currentCity][i], alpha);
        sum += pheromone_i * pow(cities[currentCity][i], beta);
    }

    return (sum != 0) ? (pheromone * heuristicValue) / sum : 0;
}

void Colony::addCityToAntsPath(Ant& currentAnt){
    std::vector<double> probabilities;
    std::vector<int> availableCities;
    int currentCity = currentAnt.visited.back();

    // Budowanie listy dostępnych miast i obliczanie prawdopodobieństw dla nich
    for (int i = 0; i < numberOfCities; i++) {
        if (currentAnt.contains(i)) {
            probabilities.push_back(calculateProbability(currentCity, i, currentAnt));
            availableCities.push_back(i);
        }
    }

    int newCityIndex = selectNextCity(probabilities);
    if (newCityIndex == -1) {
        std::cout << "Critical ERROR -> -1 occurred" << std::endl;
    } else {
        currentAnt.visited.push_back(availableCities[newCityIndex]); // Dodanie miasta z listy dostępnych
        updatePheromones(currentAnt);

    }
}

int Colony::selectNextCity(const std::vector<double>& probabilities) {
    double randomValue = ((double) rand() / (RAND_MAX)) * std::accumulate(probabilities.begin(), probabilities.end(), 0.0);

    double cumulativeProbability = 0.0;
    for (int i = 0; i < probabilities.size(); ++i) {
        cumulativeProbability += probabilities[i];
        if (cumulativeProbability >= randomValue) {
            return i; // Zwraca indeks w wektorze prawdopodobieństw, który odpowiada dostępnemu miastu
        }
    }

    return -1; // W przypadku, gdyby żadne miasto nie zostało wybrane
}

void Colony::updatePheromones(Ant &ant) {
            int from = ant.visited[ant.visited.size()-2];
            int to = ant.visited[ant.visited.size()-1];
            pheromones[from][to] += (1.0/cities[from][to]);

    }


void Colony::sortTheColony() {
    std::sort(ants.begin(), ants.end(), [](const Ant &a, const Ant &b) {
        return a.pathValue < b.pathValue;
    });
}

int Colony::calculatePathCost(std::vector<int> path, std::vector<std::vector<int>> matrix) {
    int cost = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        cost += matrix[path[i]][path[i + 1]];
    }
//    std::cout << "path cost: " << cost << std::endl;
    return cost;
}