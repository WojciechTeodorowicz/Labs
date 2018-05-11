#include "Semaphore.h"
#include <mutex>
#include <queue>

class SafeBuffer
{
public:
    std::queue<char> buffer ;
    std::shared_ptr<Semaphore> mutex; 
    std::shared_ptr<Semaphore> spaces;
    std::shared_ptr<Semaphore> units;
    SafeBuffer(int);
    void Producer(char);
    char Consumer();
};
