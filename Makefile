CC=g++
LDFLAGS= 
CFLAGS= -O3

.PHONY: all clean

all: maxflow 

maxflow: graph.o example.cpp
	$(CC) $(LDFLAGS) example.cpp graph.o -o maxflow

graph.o: graph.h graph.cpp
	$(CC) $(CFLAGS) -c graph.cpp

clean:
	rm -v maxflow *.o 