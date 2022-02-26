#include "verifyFileExtension.h"

std::string verifyFileExtension(std::string pathToExtension){
    return pathToExtension.substr(pathToExtension.find_last_of(".") + 1);
}