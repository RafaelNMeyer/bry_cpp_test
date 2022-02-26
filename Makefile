CC=g++

CFLAGS= -Wall

GCCFLAGS= -lcrypto -lstdc++fs

RELATIVEPATH=default

EXE=./bin/print default

COMPILE=$(CC) $(CFLAGS) -o $(EXE) src/main.cpp src/helpers/verifyFileExtension.cpp src/certificateFunctions/CertificateFunctions.cpp $(GCCFLAGS) 

install-dependencies:
	sudo apt-get install libssl-dev

read-all-files: all clean

read-path $(RELATIVEPATH): read-all-files

all:
	$(COMPILE)
	$(EXE)

compile:
	$(COMPILE)

print:
	$(EXE)

clean:
	rm -rf *o $(EXE)