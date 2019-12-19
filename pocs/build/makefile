all: http_s parser rabbit dbconnect

http_s: http https

rabbit: publisher subscriber

http: ../../include/httplib.hpp ../https/http.cpp packages
		g++ ../https/http.cpp -o http_poc

https: ../../include/httplib.hpp ../https/https.cpp packages
		g++ ../https/https.cpp -o https_poc -lcrypto -lssl -lcurl

parser: ../parser/parser.cpp packages
		g++ ../parser/parser.cpp -o parser

publisher: ../rabbit/publisher.cpp packages
		g++ ../rabbit/publisher.cpp -o publisher -lSimpleAmqpClient

subscriber: ../rabbit/subscriber.cpp packages
		g++ ../rabbit/subscriber.cpp -o subscriber -lSimpleAmqpClient

dbconnect: ../dbconnect/dbconnect.cpp packages
		g++ ../dbconnect/dbconnect.cpp -o dbconnect -lmysqlcppconn

packages: boost rabbitmqc rabbitmqcpp parser httpp mysql

boost:
		sudo apt-get install libboost-all-dev

rabbitmqc:
		git clone https://github.com/alanxz/rabbitmq-c
		cd ./rabbitmq-c && mkdir build && cd ./build && sudo cmake .. && sudo cmake --build . --target install
		sudo rm -rf ./rabbitmq-c

rabbitmqcpp:
		git clone https://github.com/alanxz/SimpleAmqpClient
		cd ./SimpleAmqpClient && mkdir build && cd ./build && sudo cmake .. && sudo cmake --build . --target install
		sudo rm -rf ./SimpleAmqpClient

parser:
		git clone https://github.com/lexborisov/myhtml
		cd ./myhtml && make && make test && sudo make install
		sudo rm -rf ./myhtml

httpp:
		sudo apt-get install libssl-dev
		sudo apt-get install libcurl4-openssl-dev

mysql:
		sudo apt-get install libmysqlcppconn-dev