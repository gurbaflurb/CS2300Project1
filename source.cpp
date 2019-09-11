#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

int main()
{
    std::fstream file;
    std::string line;

    file.open("Amatrix");

    if(!file.is_open())
    {
        while(getline(file, line, ' '))
        {
            std::cout << line << std::endl;
        }
    }
    else
    {
        std::cout << "Failed to open file!\nQuitting!" << std::endl;    
    }
    file.close();
    
    return 0;
}
