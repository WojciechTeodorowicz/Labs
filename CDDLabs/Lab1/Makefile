#Wojciech Teodorowicz 04/10/2017
#First simple Makefile
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


CC=g++
CFLAGS=  -std=c++11 -pthread
output: signal.o Semaphore.o
	$(CC) $(CFLAGS) signal.o Semaphore.o -o output

signal.o: signal.cpp
	$(CC) -c $(CFLAGS) signal.cpp

Semaphore.o: Semaphore.cpp Semaphore.h
	$(CC) -c $(CFLAGS) Semaphore.cpp

CLEAN:
	rm *.o
