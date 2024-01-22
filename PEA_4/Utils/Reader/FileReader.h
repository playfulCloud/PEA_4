//
// Created by Jakub on 20.01.2024.
//

#ifndef PEA_4_FILEREADER_H
#define PEA_4_FILEREADER_H


#include <vector>
#include <string>

class FileReader {

    void displayReadMatrix(std::vector<std::vector<int>> &adjacencyMatrix);

    std::vector<std::vector<int>> readFromFile2(std::__cxx11::basic_string<char> fileName);

public:
    std::vector<std::vector<int>> readFromFile();
};


#endif //PEA_4_FILEREADER_H
