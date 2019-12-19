httpsclib: httpsc.o ../../include/httpsc.hpp packages
		g++ httpsc.o -shared -lcrypto -lssl -lcurl -o /usr/lib/libhttpsc.so

httpsc.o: ../../include/httpsc.hpp ../httpsc.cpp
		g++ ../httpsc.cpp -fPIC -c -o httpsc.o

packages:
		sudo apt-get install libssl-dev
		sudo apt-get install libcurl4-openssl-dev