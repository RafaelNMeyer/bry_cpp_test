#include <string>
#include <iostream>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/bio.h>
#include <filesystem>
#include <experimental/filesystem>

#include "CertificateFunctions.h"
#include "../helpers/verifyFileExtension.h"


using namespace std;
namespace fs = experimental::filesystem;


    X509* CertificateFunctions::readFromDisk(string pathToCertificate)
    {
        X509 * certificate;
        FILE *fp = fopen(pathToCertificate.c_str(), "r");
        
        if (!fp)
        {
            std::cout << "Could not open certificate";
            return 0;
        }

        string fileExtension = verifyFileExtension(pathToCertificate);

        if(fileExtension == "crt" || fileExtension == "pem")
            certificate = PEM_read_X509(fp, NULL, NULL, NULL);
        else
            if(fileExtension == "cer" || fileExtension == "der")
                certificate = d2i_X509_fp(fp, NULL);

        if (!certificate)
        {
            std::cout << "Could not parse certificate";
            return 0;
        }
        fclose(fp);
        return certificate;
    }

    void CertificateFunctions::printSubjectName(X509* certificate){
        X509_NAME *subject = X509_get_subject_name(certificate); 
        if(!subject)
            std::cout << "Subject: \n"<< "Could not get subject name! :(" << "\n\n";
        else
            std::cout << "Subject: \n"<< X509_NAME_print_ex_fp(stdout, subject, 0, XN_FLAG_MULTILINE) << "\n\n";
    }

    void CertificateFunctions::printSerialNumber(X509* certificate){
        ASN1_INTEGER* asn1_serial = X509_get_serialNumber(certificate);
        BIO *bp = BIO_new_fp(stdout, BIO_NOCLOSE); 
        cout << "Serial Number: " << i2a_ASN1_INTEGER(bp, asn1_serial) << "\n\n";
        BIO_free(bp);
    }

    void CertificateFunctions::printNotBefore(X509* certificate){
        const ASN1_TIME *asn1NotBefore = X509_get0_notBefore(certificate);
        BIO *bp = BIO_new_fp(stdout, BIO_NOCLOSE); 
        cout << "Issued On: "<< ASN1_TIME_print(bp, asn1NotBefore) << "\n\n";
        BIO_free(bp);
    }

    void CertificateFunctions::printNotAfter(X509* certificate){
        const ASN1_TIME *asn1NotAfter = X509_get0_notAfter(certificate);
        BIO *bp = BIO_new_fp(stdout, BIO_NOCLOSE); 
        cout << "Expires On: "<< ASN1_TIME_print(bp, asn1NotAfter) << "\n\n";
        BIO_free(bp);
    }

    void CertificateFunctions::printPublicKey(X509* certificate){
        EVP_PKEY *pkey = X509_get_pubkey(certificate);
        BIO *bp = BIO_new_fp(stdout, BIO_NOCLOSE);
        if(pkey == NULL)
            std::cout << "Public Key: \n"<< "Could not get the public key! :(" << "\n\n";
        else
            std::cout << "Public Key: \n" << EVP_PKEY_print_private(bp, pkey, 1, NULL) << "\n\n";
        free(pkey);
        BIO_free(bp);
    }

    void CertificateFunctions::printAllInfos(X509* certificate){
        printSubjectName(certificate);
        printSerialNumber(certificate);
        printNotBefore(certificate);
        printNotAfter(certificate);
        printPublicKey(certificate);
    }

    void CertificateFunctions::readAndPrintAllFromPath(string relativePath){
        string pathToCertificate = "";
        for (const auto & entry : fs::directory_iterator(relativePath)){
            pathToCertificate = entry.path();
            std::string filename = pathToCertificate.substr(pathToCertificate.find_last_of("/\\") + 1);

            std::cout << "\n\n----------" << filename << "----------\n\n";
            X509 *certificate = readFromDisk(pathToCertificate);
            printAllInfos(certificate);
            std::cout << "----------" << filename << "----------\n\n";
        }
    }
