#include <string.h>
#include <iostream>

#include "certificateFunctions/CertificateFunctions.h"
#include "helpers/getFileName.h"

using namespace std;

int main(int argc, char **argv)
{
    CertificateFunctions certificateFunctions;

    cout << "\n";
    if(argc < 2) {
        cout << "Missing arguments" << "\n\n"; 
        return 0;
    }
    if(strcmp(argv[1], "true")){
        X509* certificate = certificateFunctions.readFromDisk(argv[2]);
        certificateFunctions.printAllInfos(certificate);
    } else{
        certificateFunctions.readAndPrintAllFromPath(argv[2]);
    }
    return 0;
}