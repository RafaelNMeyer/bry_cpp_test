CC=g++

CFLAGS= -Wall

all: 
	$(CC) $(CFLAGS) -o print src/main.cpp src/certificateFunctions/CertificateFunctions.cpp -lcrypto


run:
	./print

clean:
	rm -rf *o print