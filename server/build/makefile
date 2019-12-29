all: ../../include/server.hpp ../../include/search.hpp server.o
		g++ ../server_main.cpp server.o -o server -lsearch
		
server.o: ../../include/server.hpp ../../include/search.hpp
		g++ ../server.cpp -c -o server.o