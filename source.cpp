#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

int main()
{
    std::fstream file;
    std::string line;

    file.open("MatrixA.txt");

    if(!file.is_open())
    {
        while(getline(file, line))
        {
            std::cout << line << std::endl;
            if(line == "2")
            {
                int value = stoi(line);
                std::cout << "Converted string to number: " << value << std::endl;
            }
        }
        file.close();
    }
    else
    {
        std::cout << "Failed to open file!\nQuitting!" << std::endl;
        file.close();    
    }

    int n = 10;
    int arr1[10][10] = {1,2,3};
    int arr2[10][10] = {2,3,4};
    int value = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout << arr1[i][j] << ", ";
            if(j == 9)
            {
                std::cout << '\n';
            }
            value = value + (arr1[i][j] *arr2[i][j]);
        }
    }

    std::cout << "Dot Product: " << value << std::endl; 
    
    return 0;
}
