#include "getFileName.h"

std::string getFileName(std::string pathToFile){
    return pathToFile.substr(pathToFile.find_last_of("/\\") + 1);
}