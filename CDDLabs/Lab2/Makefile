#Wojciech Teodorowicz 04/10/2017
#First simple Makefile
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


CC=g++
CFLAGS=  -std=c++11 -pthread
#output: Rendezvous.o Semaphore.o
#	$(CC) $(CFLAGS) Rendezvous.o Semaphore.o -o output

#Rendezvous.o: Rendezvous.cpp
#	$(CC) -c $(CFLAGS) Rendezvous.cpp

Rendezvous: Semaphore.cpp Semaphore.h Rendezvous.cpp
	$(CC) $(CFLAGS) -o Rendezvous Semaphore.cpp Semaphore.h Rendezvous.cpp

CLEAN:
	rm *.o
