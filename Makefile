#Makefile
all: fakessid

fakessid: fakessid.o
	g++ -o fakessid fakessid.o -O3 -std=c++11 -lpthread -ltins 

fakessid.o: fakessid.cpp
	g++ -c -o fakessid.o fakessid.cpp -O3 -std=c++11 -lpthread -ltins

clean:
	rm -f fakessid
	rm -f *.o
