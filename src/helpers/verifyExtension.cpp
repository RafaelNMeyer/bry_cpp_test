#include "verifyExtension.h"

std::string verifyExtension(std::string pathToExtension){
    return pathToExtension.substr(pathToExtension.find_last_of(".") + 1);
}