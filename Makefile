CC=g++

CFLAGS= -Wall

COMPILE=$(CC) $(CFLAGS) -o print src/main.cpp src/helpers/verifyExtension.cpp src/certificateFunctions/CertificateFunctions.cpp -lcrypto

all: 
	$(COMPILE)

run:
	$(COMPILE)
	./print

clean:
	rm -rf *o print