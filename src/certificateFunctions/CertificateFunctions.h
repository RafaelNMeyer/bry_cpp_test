#include <string>
#include <iostream>
#include <openssl/x509.h> // x509 implementation
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/bio.h>

class CertificateFunctions
{
public:
    X509* readFromDisk(std::string pathToCertificate);
    void printSubjectName(X509* certificate);
    void printSerialNumber(X509* certificate);
    void printNotBefore(X509* certificate);
    void printNotAfter(X509* certificate);
    void printPublicKey(X509* certificate);
    void printAllInfos(X509* certificate);
};