//
// Created by theow on 22.07.2025.
//

#include "threadpool.h"
#include "../../util/logSys/logsys.h"

// Constructors

taskQueue::taskQueue() {

logSys.info("Task Queue created");

}

taskQueue::~taskQueue() {
    logSys.info("Task Queue destroyed");
}

threadPool::threadPool(uint8_t threadcount) {
    logSys.info("Pool created");
    std::cout << std::thread::hardware_concurrency() << std::endl;


}

threadPool::~threadPool() {
    logSys.info("Pool destroyed");
}

void task::createTask(int taskPriority, std::function<void()> func, size_t taskId) {


}
