all: ../../include/crawler.hpp ../../include/publisher.hpp ../../include/threadpool.hpp ../../include/lqueue.hpp crawler.o
		g++ ../crawler_main.cpp crawler.o -o crawler -lmqueue -lthreadpool -llqueue

crawler.o: ../../include/crawler.hpp ../../include/publisher.hpp ../../include/threadpool.hpp ../../include/lqueue.hpp
		g++ ../crawler.cpp -c -o crawler.o