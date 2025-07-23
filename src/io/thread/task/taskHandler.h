//
// Created by theow on 22.07.2025.
//

#ifndef TASKHANDLER_H
#define TASKHANDLER_H
#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>


class taskHandler
{
    public:
        taskHandler();
        ~taskHandler();
        void taskQueueAdd();
        void taskQueueRemove();
        void assingTaskToPool();
};


class task
{
    public:
        int taskSize;
        int taskPriority;
        std::function<void()> taskFunction;
        size_t taskId;
        int maxRetryCount = 3;
        std::mutex taskMutex;
};


class taskQueue
{
    public:
        std::queue<task> tasks;
        std::mutex queueMutex;
        std::condition_variable condition;
        size_t maxqueueSize = 100;
    private:
        bool stop = false;
};

#endif //TASKHANDLER_H
