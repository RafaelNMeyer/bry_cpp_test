#include <string.h>
#include <iostream>

#include "certificateFunctions/CertificateFunctions.h"
#include "helpers/getFileName.h"

using namespace std;


int main(int argc, char **argv)
{
    CertificateFunctions certificateFunctions;
    string path = "./assets/certificates";

    if(strcmp(argv[1], "default")){
        certificateFunctions.readAndPrintAllFromPath(path);
    } else{
        
    }

    return 0;
}