//
// Created by theow on 22.07.2025.
//

#include "threadpool.h"
#include "../../util/logSys/logsys.h"

// Constructors

task::taskQueue::taskQueue() {

logSys.info("Task Queue created");

}

task::taskQueue::~taskQueue() {
    logSys.info("Task Queue destroyed");
}

threadpool::pool::pool() {
    logSys.info("Pool created");
}

threadpool::pool::~pool() {
    logSys.info("Pool destroyed");
}

void task::task::createTask(int taskPriority, std::function<void()> func, size_t taskId) {



}
