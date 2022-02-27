#include <openssl/x509.h> // x509 implementation


class CertificateFunctions
{
public:
    // Read the certificate from disk and return it
    X509* readFromDisk(std::string pathToCertificate);
    
    // Print the subject name of the certificate
    void printSubjectName(X509* certificate);

    // Print the serial number of the certificate
    void printSerialNumber(X509* certificate);

    // Print the issued date of the certificate
    void printNotBefore(X509* certificate);

    // Print the expiration date of the certificate
    void printNotAfter(X509* certificate);

    // Print the public key of the certificate
    void printPublicKey(X509* certificate);

    // Print the Subject name, serial numberm issued date,
    // expiration date and public key of the certificate
    void printAllInfos(X509* certificate);

    // Read all certificates from a folder and print all informations
    void readAndPrintAllFromPath(std::string relativePath);
};