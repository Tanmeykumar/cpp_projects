#include <iostream>
#include "file.h"
int main()
{
    int choice = 0;
    char cont = 'y';
    File objFile;
    while (cont == 'y' || cont == 'Y')
    {
        std::cout << "Enter your choice :" << std::endl;
        std::cout << "1. Creation of file\t2. Writing to File\t3. Reading from File\t 4. Deletion of File" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Creating File" << std::endl;
            objFile.createFile();
            // createFile();
            break;
        case 2:
            std::cout << "Writing File" << std::endl;
            objFile.writeFile();
            // writeFile();
            break;
        case 3:
            std::cout << "Deleting File" << std::endl;
            objFile.readFile();
            // deleteFile();
            break;
        case 4:
            std::cout << "Deleting File" << std::endl;
            objFile.deleteFile();
            // deleteFile();
            break;
        default:
            std::cout << "Wrong choice!, try again" << std::endl;
            break;
        }
        cont = 'n';
        std::cout << "do you want to continue??[y/n]" << std::endl;
        std::cin >> cont;
    }
    return 0;
}