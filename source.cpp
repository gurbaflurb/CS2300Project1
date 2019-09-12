/*
Sean Chen
Last modified: Sept. 12, 2019
source.cpp

This program reads in from a file and builds a vector of the correct size based on the given files. Then the program writes these matrixes to files and to the screen
The program then does the matrix math required and outputs the result to a file and to the screen. Then the program does a transpose of the result and outputs the matrix
to the screen and to a file.
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <tuple>
#include <vector>

/*
Tuple function
Takes in a string for the path to the file you wish to open.
Returns a tuple in the form of int, int, vector.
*/
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

/*
writeData function
Takes in an int for the size of the row and an int for the size of the columns, an integer vector as the matrix, and a string for the name of the output file
Prints the contents of the vector to the screen and to a file
*/
void writeData(int rows, int columns, std::vector<int> matrix, std::string fileName)
{
    for(int i = 0; i < columns; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            std::cout << matrix[i+j] << ", ";
        }
        std::cout << std::endl;
    }
}

//Main
int main()
{
    int row1, row2, column1, column2;
    std::vector<int> matrix1;
    std::vector<int> matrix2;

    std::tie(row1, column1, matrix1) = readData("Amatrix");
    std::tie(row2, column2, matrix2) = readData("Bmatrix");

    writeData(row1, column1, matrix1, "CS2300P1aChen.outA");
    writeData(row2, column2, matrix2, "CS2300P1aChen.outB");
    return 0;
}
