all: ../../include/crawler.hpp ../../include/publisher.hpp ../../include/threadpool.hpp ../../include/lqueue.hpp ../include/httpsc.hpp crawler.o
		g++ ../crawler_main.cpp crawler.o -o crawler -lmqueue -lthreadpool -llqueue -lhttpsc

crawler.o: ../../include/crawler.hpp ../../include/publisher.hpp ../../include/threadpool.hpp ../../include/lqueue.hpp ../include/httpsc.hpp
		g++ ../crawler.cpp -c -o crawler.o