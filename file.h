#include <iostream>
#include <string>
#include <limits>
#include <string.h>
class File
{
public:
    enum FileOpenMode
    {
        FILE_CREATE,
        FILE_WRITE,
        FILE_READ
    };
    std::string m_fileName;
    FILE *m_file;
    int seekToBegin() { return fseek(m_file, 0, SEEK_SET); }
    int seekToEnd() { return fseek(m_file, 0, SEEK_END); }
    int currentPos() { return fseek(m_file, 0, SEEK_CUR); }
    int getFileLength()
    {
        seekToEnd();
        return ftell(m_file);
    }
    void createFile();
    void deleteFile();
    void writeFile();
    void readFile();
    bool openFile(std::string fileName, FileOpenMode fileMode);
};