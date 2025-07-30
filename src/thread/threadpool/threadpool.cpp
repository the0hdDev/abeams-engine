#include "threadpool.h"
#include "../../io/util/logsys/logsys.h"

taskQueue::taskQueue() {

    logSys.info("Task Queue created");
}

taskQueue::~taskQueue() {

    logSys.info("Task Queue destroyed");
}

void doWork(int i) {
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
}

threadPool::threadPool(uint16_t threadcount) {
    if (threadcount <= 0) {
        logSys.critical("Thread count must be greater than 0");
        return;
    }
    if (threadcount > std::thread::hardware_concurrency()) {
        logSys.warning("Thread count exceeds hardware concurrency, this will impact performance negatively!");
    }
    assingWorkerThreads(threadcount);
    logSys.info("Pool created");
}

threadPool::~threadPool() {
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }
    logSys.info("Pool destroyed");
}

void threadPool::assingWorkerThreads(uint16_t threadcount)
{
    for (int i = 0; i < threadcount; i++) {
        threads.emplace_back(doWork, i);
    }
    logSys.info("Created " + std::to_string(threadcount) + " worker threads");
}