CC=g++

CFLAGS= -Wall

GCCFLAGS= -lcrypto -lstdc++fs

RELATIVEPATH=default

EXE=./bin/print

COMPILE=$(CC) $(CFLAGS) -o $(EXE) src/main.cpp src/helpers/verifyFileExtension.cpp src/certificateFunctions/CertificateFunctions.cpp $(GCCFLAGS) 

install-dependencies:
	sudo apt-get install libssl-dev

all:
	$(COMPILE)
	$(EXE) $(read-all) $(path)

compile:
	$(COMPILE)

clean:
	rm -rf *o $(EXE)