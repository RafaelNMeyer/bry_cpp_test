main: main.o CertificateFunctions.o
	g++ main.o CertificateFunctions.o -o main

main.o: ./src/main.cpp
	g++ -c ./src/main.cpp

CertificateFunctions.o: ./src/certificateFunctions/CertificateFunctions.cpp
	g++ -c ./src/certificateFunctions/CertificateFunctions.cpp

clean:
	rm *.o main