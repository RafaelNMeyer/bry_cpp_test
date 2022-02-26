#include <openssl/x509.h> // x509 implementation


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
    void readAndPrintAllFromPath(std::string relativePath);
};