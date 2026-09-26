#pragma once
#include<vector>
#include<iostream>
#include<thread>
#include<functional>
#include<mutex>
#include<condition_variable>
#include<queue>
class ThreadPool
{
private:
    std::vector<std::thread>workers;
    std::queue<std::function<void()>>tasks;
    std::mutex mutex;
    std::condition_variable cv;
    bool stop=false;
    void worker();
public:
    explicit ThreadPool(int ThreadCount);
    void submit(std::function<void()>task);
    ~ThreadPool();
    ThreadPool(const ThreadPool&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;
};