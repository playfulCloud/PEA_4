//
// Created by Jakub on 20.01.2024.
//

#include "FileReader.h"
//
// Created by playfulCloud on 12/27/23.
//

#include "FileReader.h"
#include "FileReader.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <sstream>
#include <vector>


std::vector<std::vector<int>> FileReader::readFromFile() {
    std::cout << "Enter the name of file you want to read: ";
    std::string fileName;
    std::cin >> fileName;
    std::fstream file;
    std::filesystem::path projectPath = std::filesystem::current_path();
    projectPath = projectPath.parent_path();
    std::string filePath = projectPath.string() + "\\Data\\" + fileName;
    std::cout << filePath << std::endl;
    file.open(filePath, std::ios::in);

    if (!file.is_open()) {
        std::cout << "Nie można otworzyć pliku" << std::endl;
        return {};
    }

    std::string line;
    int dimension = 0;
    // Extracting dimension value
    while (getline(file, line)) {
        if (line.find("DIMENSION:") != std::string::npos) {
            std::istringstream iss(line.substr(line.find(":") + 1));
            iss >> dimension;
            break;
        }
    }

    // Inicjalizacja macierzy sąsiedztwa
    std::vector<std::vector<int>> adjacencyMatrix(dimension, std::vector<int>(dimension, 0));

    bool startReading = false;
    int row = 0, col = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find("EOF") != std::string::npos) {
                break;
            }
            if (line.find("EDGE_WEIGHT_SECTION") != std::string::npos) {
                startReading = true;
                continue;
            }

            if (startReading) {
                std::istringstream iss(line);
                int number;
                while (iss >> number) {
                    adjacencyMatrix[row][col] = number;
                    if (++col == dimension) {
                        col = 0;
                        if (++row == dimension) break; // Przerwij, jeśli wypełniono całą macierz
                    }
                }
            }
        }
    }

    file.close();
//    displayReadMatrix(adjacencyMatrix);
    return adjacencyMatrix;
}

void FileReader::displayReadMatrix(std::vector<std::vector<int>> &adjacencyMatrix) {// Opcjonalne: Drukowanie macierzy sąsiedztwa
    for (const auto &row : adjacencyMatrix) {
        for (int weight : row) {
            std::cout << weight << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "File has been read" << std::endl;
}


std::vector<std::vector<int>> FileReader::readFromFile2(std::string fileName) {
    std::fstream file;
    std::filesystem::path projectPath = std::filesystem::current_path();
    projectPath = projectPath.parent_path(); // Uzyskanie ścieżki do katalogu nadrzędnego
    std::string filePath = projectPath.string() + "\\Data\\" + fileName;
    std::cout << filePath << std::endl;
    file.open(filePath, std::ios::in);

    if (!file.is_open()) {
        std::cout << "Nie można otworzyć pliku" << std::endl;
        return {}; // Zwraca pustą macierz, jeśli plik nie może być otwarty
    }

    std::string line;
    int dimension = 0;
    // Extracting dimension value
    while (getline(file, line)) {
        if (line.find("DIMENSION:") != std::string::npos) {
            std::istringstream iss(line.substr(line.find(":") + 1));
            iss >> dimension;
            break;
        }
    }

    std::vector<std::vector<int>> adjacencyMatrix(dimension, std::vector<int>(dimension, 0));

    bool startReading = false;
    int row = 0, col = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find("EOF") != std::string::npos) {
                break;
            }
            if (line.find("EDGE_WEIGHT_SECTION") != std::string::npos) {
                startReading = true;
                continue;
            }

            if (startReading) {
                std::istringstream iss(line);
                int number;
                while (iss >> number) {
                    adjacencyMatrix[row][col] = number;
                    if (++col == dimension) {
                        col = 0;
                        if (++row == dimension) break; // Przerwij, jeśli wypełniono całą macierz
                    }
                }
            }
        }
    }

    file.close();

    return adjacencyMatrix;
}