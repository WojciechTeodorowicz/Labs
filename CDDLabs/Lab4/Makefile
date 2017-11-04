#@author: Wojciech Teodorowicz
#@date: 04/10/17
#@lastUpdated: 30/10/17



CC=g++
CFLAGS=  -std=c++11 -pthread
#output: Rendezvous.o Semaphore.o
#	$(CC) $(CFLAGS) Rendezvous.o Semaphore.o -o output

ALL: Semaphore.cpp Semaphore.h Barrier.cpp
	$(CC) $(CFLAGS) -o Barrier Semaphore.cpp Semaphore.h Barrier.cpp

CLEAN:
	rm *.o
