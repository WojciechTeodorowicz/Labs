#include "Semaphore.h"
#include <iostream>
#include <thread>

void ThreadA(std::shared_ptr<Semaphore> SemA, std::shared_ptr<Semaphore> SemB){
  std::cout << "ThreadA: First A Thread" << std::endl;
  SemA->Signal();
  SemB->Wait();

  std::cout << "ThreadA: Second A Thread " << std::endl;
}
void ThreadB(std::shared_ptr<Semaphore> SemA, std::shared_ptr<Semaphore> SemB){
  std::cout << "ThreadB : First B thread" << std::endl;
  SemB->Signal();
  SemB->Wait();

  std::cout << "ThreadB : Second B Thread" << std::endl;
}
int main(void){
std::thread threadA, threadB;
std::shared_ptr<Semaphore> SemA( new Semaphore);
std::shared_ptr<Semaphore> SemB( new Semaphore);

threadA=std::thread(ThreadA, SemA, SemB);
threadB=std::thread(ThreadB, SemB, SemB);

  
 threadA.join();
 threadB.join();
 return 0;

}
