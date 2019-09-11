#include <iostream>
#include <cstdlib>
#include <fstream>
#include <tuple>
#include <vector>

std::tuple<int, int, std::vector<int>> readData(std::string filePath)
{
    std::vector<int> matrix;
    std::fstream file;
    std::string line;
    int rows;
    int columns;
    file.open(filePath);

    if(file.is_open())
    {
        std::getline(file, line, ' ');
        rows = stoi(line);
        std::getline(file, line, ' ');
        columns = stoi(line);

        for (int i = 0; i < columns; i++)
        {
            for(int j = 0; j < rows; j++)
            {
                std::getline(file, line, ' ');
                matrix.push_back(stoi(line));
            }
        }
    }
    else
    {
        std::cout << "Failed to open file!\nQuitting!" << std::endl; 
    }
    file.close();
    return std::make_tuple(rows, columns, matrix);
}

int main()
{
    int row1, row2, column1, column2;
    std::vector<int> matrix1;
    std::vector<int> matrix2;

    std::tie(row1, column1, matrix1) = readData("Amatrix");
    std::tie(row2, column2, matrix2) = readData("Bmatrix");

    for(int i = 0; i < column1; i++)
    {
        for(int j = 0; j < row1; j++)
        {
            std::cout << matrix1[i+j] << ", ";
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < column2; i++)
    {
        for(int j = 0; j < row2; j++)
        {
            std::cout << matrix2[i+j] << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}
