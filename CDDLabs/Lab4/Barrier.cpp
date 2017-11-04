/*! 
      @author: Wojciech Teodorowicz
@date created: 24/10/17
     @version: 0.9
 @lastUpdated: 30/10/17
     @purpose: Reuseable Barrier
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <string>
#include <vector>

int num_Threads= 6;
int counter = 0;

void funcOne(std::shared_ptr<Semaphore> mutex, std::shared_ptr<Semaphore> barrier1, std::shared_ptr<Semaphore> barrier2, int thread_Number) {

  mutex->Wait();
  counter++;
  if (counter == num_Threads) {
     barrier2-> Wait();
     barrier1-> Signal();
  }


  mutex->Signal();
  barrier1->Wait();
   /*rendezvous1 */
  std::cout << thread_Number <<  "Stop here!" <<std::endl;
  barrier1->Signal();
  mutex->Wait();
  counter--;

  if(counter == 0) {
    barrier1->Wait();
    barrier2->Signal();
  }
  mutex->Signal();
  barrier2->Wait();
  barrier2->Signal();
   /*rendezvous2 */
  std::cout << thread_Number << "Go! " <<std::endl;
  
}

int main(void) {

   /*for turnstyle */
  std::shared_ptr<Semaphore> barrier1(new Semaphore(0));
  std::shared_ptr<Semaphore> barrier2(new Semaphore(1));
  /*create an array for the number of threads */
  std::thread tArray[num_Threads];
  std::shared_ptr<Semaphore> mutex(new Semaphore(1));

  for (int i = 0; i < num_Threads; i++) {
    tArray[i] = std::thread(funcOne,mutex,barrier1,barrier2,i);
  }

  /*for output*/
  for (int i = 0; i < num_Threads; i++) {
    tArray[i].join();
  }
  return 0;
}
