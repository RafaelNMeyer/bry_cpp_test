#include <string>
#include <iostream>
#include "certificateFunctions/CertificateFunctions.h"

using namespace std;

int main(int argc, char **argv)
{   
    CertificateFunctions certificates;

    X509* certificate = certificates.readFromDisk("a");

    certificates.printAllInfos(certificate);

    return 0;
}