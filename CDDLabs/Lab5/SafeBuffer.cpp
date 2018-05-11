#include "SafeBuffer.h"

SafeBuffer::SafeBuffer(int max=0){

  mutex = std::make_shared<Semaphore>(1);
  units  = std::make_shared<Semaphore>(0);
  spaces = std::make_shared<Semaphore>(max);
}

void SafeBuffer::Producer(char d)
{
    spaces->Wait();
    mutex->Wait();
    buffer.push(d);
    mutex->Signal();
    units->Signal();
}

char SafeBuffer::Consumer()
{
    char d;
    units->Wait();
    mutex->Wait();
    d = buffer.front();
    buffer.pop();
    mutex->Signal();
    spaces->Signal();
    return d;
}
