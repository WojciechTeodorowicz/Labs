#include "SafeBuffer.h"
#include <stdlib.h>  
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

 
int ProCon [10] = {0};

void produce(int RandomNum, std::shared_ptr<SafeBuffer> buffer) {
	for(int i = 0; i < RandomNum; ++i) {
		int n = std::rand() % 13;
		char d = (char)(n + 55);
		buffer->Producer(d);
		std::cout << "Producer Amount: " << d << std::endl;
	}
	buffer->Producer('X');
}

void consume(std::shared_ptr<SafeBuffer> buffer) {
	char d;
	do {
		d = buffer->Consumer();
		std::cout << "Consumer Amount: " << d << std::endl;
    	std::this_thread::sleep_for(std::chrono::milliseconds(std::rand()%1000));
		ProCon[(int(d))-55]++;
	} while ( d != 'X');
}

void createThreads(int RandomNum, std::shared_ptr<SafeBuffer> buffer) {

	std::vector<std::thread> threads;

      
	threads.push_back(std::thread(produce, RandomNum, buffer));
	threads.push_back(std::thread(consume, buffer));

        
	for(auto& thread : threads) {
		thread.join();
	}
}

void ProConPrint() {
	std::cout << "Characters Number: \n";
	for ( char i = 55; i < 123; ++i ) {
		std::cout << i << " : " << ProCon[i-55] << "\n";
		
	}

}


int main(void){
	
	int RandomNum = rand() % 60 + 30;

	std::shared_ptr<SafeBuffer> buffer(new SafeBuffer(RandomNum));

	createThreads(RandomNum, buffer);


	ProConPrint();	
	
	std::cout << " \n";

	return 0;
}
