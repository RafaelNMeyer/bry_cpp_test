#include <string.h>
#include <iostream>

#include "certificateFunctions/CertificateFunctions.h"
#include "helpers/getFileName.h"

using namespace std;

// make all read-all=true path=./assets/certificates
// make all read-all=false path=/home/rafael/Documents/bry_cpp_test/assets/certificates/certificado-ac-raiz-bry-v3.crt

int main(int argc, char **argv)
{
    CertificateFunctions certificateFunctions;

    cout << "\n--------------------\n\n";
    if(strcmp(argv[1], "true")){
        X509* certificate = certificateFunctions.readFromDisk(argv[2]);
        certificateFunctions.printAllInfos(certificate);
    } else{
        certificateFunctions.readAndPrintAllFromPath(argv[2]);
    }
    return 0;
}