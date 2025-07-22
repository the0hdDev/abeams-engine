//
// Created by theow on 22.07.2025.
//

#ifndef TASKHANDLER_H
#define TASKHANDLER_H
#include <condition_variable>
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
