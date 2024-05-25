#include "file.h"

void File::createFile()
{
    std::cout << "Enter the name of the file :" << std::endl;
    std::cin >> m_fileName;
    if (openFile(m_fileName, FILE_CREATE))
    {
        std::cout << "File created successfully !!" << std::endl;
        fclose(m_file);
    }
}

void File::deleteFile()
{
    std::cout << "Enter the name of the file :" << std::endl;
    std::cin >> m_fileName;
    if (openFile(m_fileName, FILE_READ))
    {
        if (remove(m_fileName.c_str()) != 0)
        {
            std::cout << "File couldn't be found!!" << std::endl;
            fclose(m_file);
            return;
        }
        std::cout << "File deleted successfully !!" << std::endl;
        fclose(m_file);
    }
}

void File::writeFile()
{

    char *charArray;
    std::string str = "";
    // char str[] = "txt is being added";
    std::cout << "Enter the name of the file :" << std::endl;
    std::cin >> m_fileName;

    std::cout << "Enter the text :" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, str);

    charArray = (char *)str.c_str();

    if (openFile(m_fileName, FILE_WRITE))
    {
        seekToEnd();
        fwrite(charArray, 1, strlen(charArray), m_file);
        fclose(m_file);
    }
}

void File::readFile()
{
    char str[100];
    std::cout << "Enter the name of the file :" << std::endl;
    std::cin >> m_fileName;
    if (openFile(m_fileName, FILE_READ))
    {
        seekToEnd();
        int lenText = getFileLength();
        seekToBegin();

        int len = fread(str, 1, lenText, m_file);

        for (int i = 0; i < lenText; i++)
        {
            std::cout << str[i];
        }
        std::cout << std::endl;

        fclose(m_file);
    }
}

bool File::openFile(std::string fileName, FileOpenMode fileMode)
{
    switch (fileMode)
    {
    case FILE_CREATE:

        m_file = fopen(fileName.c_str(), "w");
        if (m_file)
        {
            return true;
        }
        else
            return false;
        break;
    case FILE_WRITE:

        m_file = fopen(fileName.c_str(), "a");
        if (m_file)
        {
            return true;
        }
        else
            return false;
        break;
    case FILE_READ:

        m_file = fopen(fileName.c_str(), "r");
        if (m_file)
        {
            return true;
        }
        else
            return false;
        break;
    }
    return false;
}