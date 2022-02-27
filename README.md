# Certificate infos

This software allows you to print the informations of a certificate with the following encoding formats and extensions:

.pem, .crt, .der, .cer.

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

You have three ways to run the app:

### 1. Run the already compiled version of the software

The bin folder contains the "print.out" file executable.

To run it, you have 2 options:

        ./bin/print read-all=true path=./path/to/folder

        ./bin/print read-all=false path=./path/to/certificate.cer

<br>

### 2. Compile and read all certificates from folder (The best option)

In this way, you will pass with pararameter the path of the folder that contains all of your certificates.

It will print all infos of all certificates.

example:

        make all read-all=true path=./path/to/folder

<br>

### 3. Compile and read a specific certificate from folder

In this way, you will pass with parameter the path of certificate.

It will print the infos of the certificate.

example:

        make all read-all=false path=./home/path/to/certificate.cer
        