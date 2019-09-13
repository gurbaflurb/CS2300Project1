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
Takes in an int for the size of the row, an integer vector as the matrix, and a string for the name of the output file
Prints the contents of the vector to the screen and to a file
*/
void writeData(int rows, std::vector<int> matrix, std::string fileName)
{
    std::ofstream file;
    int count = 0;
    file.open(fileName);

    if(file.is_open())
    {
        for(std::vector<int>::iterator it = matrix.begin(); it != matrix.end(); it++)
        {
            if(count == rows-1)
            {
                std::cout << *it << '\n';
                file << *it << '\n';
                count = 0;
            }
            else
            {
                std::cout << *it << ", ";
                file << *it << ", ";
                count++;
            }
        }
    }

    file.close();
}

/*
multiplyByConstant function
Takes in an integer for rows, an integer matrix, and a constant integer
The function then multiplies each element of the matrix by the constant and returns a vector with said multiplied values
*/
std::vector<int> multiplyByConstant(int rows, std::vector<int> matrix, int constant)
{
    for(std::vector<int>::iterator it = matrix.begin(); it != matrix.end(); it++)
    {
        *it = *it * constant;
    }
    return matrix;
}

/*
subtractMatrixes function
Takes in two integer values for the rows and columns and two matrixes
The function then subtracts the matrixes from each other and returns the resulting matrix
*/
std::vector<int> subtractMatrixes(int rows, int columns, std::vector<int> matrix1, std::vector<int> matrix2)
{
    for(int i = 0; i < rows*columns; i++)
    {
        matrix1[i] = matrix1[i] - matrix2[i];
    }
    return matrix1;
}

/*
transposeMatrix function
Takes in an integer row and column, and an integer vector
The function then turns each rox of the matrix into a column, based on the row and column values passed to it
Then then function returns an integer vector
*/
std::vector<int> transposeMatrix(int row, int column, std::vector<int> matrix)
{
    std::vector<int> returnMatrix;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            returnMatrix.push_back(matrix[(j*column)+i]);
        }
    }
    return returnMatrix;
}

//Main
int main()
{
    int row1, row2, column1, column2;
    std::vector<int> matrix1;
    std::vector<int> matrix2;

    std::tie(row1, column1, matrix1) = readData("Amatrix");
    std::tie(row2, column2, matrix2) = readData("Bmatrix");

    std::cout << "MatrixA" << std::endl;
    writeData(row1, matrix1, "CS2300P1aChen.outA");
    std::cout << "\nMatrixB" << std::endl;
    writeData(row2, matrix2, "CS2300P1aChen.outB");
    std::cout << '\n';

    std::cout << "5A - B Calculation" << std::endl;
    matrix1 = multiplyByConstant(row1, matrix1, 5);
    matrix1 = subtractMatrixes(row1, column1, matrix1, matrix2);
    writeData(row1, matrix1, "CS2300P1aChen.calc");
    std::cout << '\n';
    std::cout << "Transpose" << std::endl;
    matrix1 = transposeMatrix(row1, column1, matrix1);
    writeData(row1, matrix1, "transpose");

    return 0;
}
