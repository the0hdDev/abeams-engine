//
// Created by theow on 22.07.2025.
//

#pragma once
#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <vector>
#include <thread>

class task
{
public:
    void createTask(int taskPriority, std::function<void()> func, size_t taskId);
private:
    int taskPriority{};
    std::function<void()> taskFunction;
    size_t taskId = 0;
    uint8_t maxRetryCount = 3;
    std::mutex taskMutex;
};

class taskQueue
{
public:
    taskQueue();
    ~taskQueue();
    std::priority_queue<task> tasks{};
    std::mutex queueMutex{};
    std::condition_variable condition{};
    size_t maxqueueSize = 100;
    bool stop = false;
};

class threadPool
{
public:
    explicit threadPool(uint16_t threadcount);
    ~threadPool();
    void assingWorkerThreads(uint16_t threadcount);

    std::vector<std::thread> threads;

    taskQueue queue;
    std::mutex threadpoolMutex;
};