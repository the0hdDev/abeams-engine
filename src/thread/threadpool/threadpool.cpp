//
// Created by theow on 22.07.2025.
//

#include "threadpool.h"
#include "../io/util/logSys/logsys.h"

// Constructors




taskQueue::taskQueue() {

logSys.info("Task Queue created");

}

taskQueue::~taskQueue() {
    logSys.info("Task Queue destroyed");
}



threadPool::threadPool(uint16_t threadcount) {
    logSys.info("Pool created");
    threadPool::assingWorkerThreads(threadcount);
    threadPool::threads = new std::vector<std::thread>();
    if (threadcount <= 0)
    {
        logSys.critical("Thread count must be greater than 0");
        return;
    }
    if (threadcount > std::thread::hardware_concurrency())
    {
        logSys.warning("Thread count exceeds hardware concurrency, this will impact performance negatively!");
    }

    std::cout << std::thread::hardware_concurrency() << std::endl;


}

threadPool::~threadPool() {
    logSys.info("Pool destroyed");
}

void task::createTask(int taskPriority, std::function<void()> func, size_t taskId) {


}

void threadPool::assingWorkerThreads(uint16_t threadcount)
{
    for (int i = 0; i < threadcount; i++)
    {
        threadPool::threads->push_back(std::thread );
    }
}
