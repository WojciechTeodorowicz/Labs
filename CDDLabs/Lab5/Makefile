
#@lastUpdated: 11/05/18
#@author: Wojciech Teodorowicz
#@date: 11/05/18
#@lastUpdated: 11/05/18


EXE = ProducerConsumer
CC=g++
CFLAGS= -std=c++11 -pthread
HFILES=Semaphore.h SafeBuffer.h
CPPFILES= ProducerConsumer.cpp SafeBuffer.cpp Semaphore.cpp


%.o: %.cpp
	$(CC) -c $(CFLAGS) $(DEBUGFLAGS)

ALL: $(HFILES) $(CFILES)
	$(CC) -o $(EXE) $(CFLAGS) $(CPPFILES) $(DEBUGFLAGS) 

DEBUG: DEBUGFLAGS = -g -O0 -Wall
DEBUG: ALL

# Generate documentation
docs: 
	doxygen doxyfile

# Remove the object files
CLEAN:
	rm *.o
