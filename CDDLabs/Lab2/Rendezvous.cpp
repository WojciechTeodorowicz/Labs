#include "Semaphore.h"
#include <iostream>
#include <thread>

void ThreadA(std::shared_ptr<Semaphore> aArrived, std::shared_ptr<Semaphore> bArrived){
  std::cout << "ThreadA: First A Thread" << std::endl;
  aArrived->Singal();
  bArrived->Wait();

  std::cout << "ThreadA: Second A Thread " << std::endl;
}
void ThreadB(std::shared_ptr<Semaphore> aArrived, std::shared_ptr<Semaphore> bArrived){
  std::cout << "ThreadB : First B thread" << std::endl;
  bArrived->Signal();
  aArrived->Wait();

  std::cout << "ThreadB : Second B Thread" << std::endl;
}
int main(void){
std::thread threadA, threadB;
std::shared_ptr<Semaphore> aArrived( new Semaphore);
std::shared_ptr<Semaphore> bArrived( new Semaphore);

threadA=std::thread(ThreadA, aArrived, bArrived);
threadB=std::thread(ThreadB, aArrived, bArrived);

  
 threadA.join();
 threadB.join();
 return 0;

}
