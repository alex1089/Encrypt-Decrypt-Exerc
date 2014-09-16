all: test

test: 
	g++490 -Wall -std=c++11 Encrypt.cpp Encrypt.h CISP400V9AD2.cpp -o test
