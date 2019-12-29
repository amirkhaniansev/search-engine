all: ../../include/indexer.hpp ../../include/db.hpp ../../include/subscriber.hpp indexer.o
		g++ ../indexer_main.cpp indexer.o -o indexer -lalitadb -lmqueue
		
indexer.o: ../../include/indexer.hpp ../../include/db.hpp ../../include/subscriber.hpp ../indexer.cpp
		g++ ../indexer.cpp -c -o indexer.o