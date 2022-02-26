# Certificate infos

This software allows you to print the certificate infos.

<br/>

## If you want to run the software on your machine, follow the tutorial bellow

<br>

# Installation (Linux)

### 1. Download the repository

        git clone git@github.com:RafaelNMeyer/bry_cpp_test.git

### 2. Install the dependencies

        make install-dependencies

<br/>

# Run the app

You have two ways to run the app:

### 1. Read all certificates from folder (The best option)

In this way, you will pass with pararameter the path of the folder that contains all of your certificates.

example:

        make all read-all=true path=assets/certificates

<br>

### 2. Read a specific certificate from folder

In this way, you will pass with parameter the path of certificate.

example:

        make all read-all=false path=/home/rafael/Documents/bry_cpp_test/assets/certificates/certificado-ac-raiz-bry-v3.crt