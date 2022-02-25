#include "CertificateFunctions.h"
#include "../helpers/verifyExtension.h"

using namespace std;

    // read certificate from disk and return a certificate
    X509* CertificateFunctions::readFromDisk(string pathToCertificate)
    {
        X509 * certificate;
        std::string pathToCert = "/home/rafael/Documents/bry_cpp_test/assets/certificates/certificado-verisign.cer";
        //std::string pathToCert = "/home/rafael/Documents/bry_cpp_test/assets/certificates/certificado-ac-raiz-bry-v3.crt";
        FILE *fp = fopen(pathToCert.c_str(), "r");
        if (!fp)
        {
            std::cout << "Could not open certificate";
            return 0;
        }

        if(verifyExtension(pathToCert) == "crt") {
            certificate = PEM_read_X509(fp, NULL, NULL, NULL);
        }else {
            certificate = d2i_X509_fp(fp, NULL);
        }

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
