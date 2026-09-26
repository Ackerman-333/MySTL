#include"include\thread_pool.hpp"
ThreadPool::ThreadPool(int threadCount)
{
    for (int i = 0; i < threadCount; ++i)
    {
        workers.emplace_back([this]
        {
            worker();
        });
    }
}
void ThreadPool::worker()
{
    while (true)
    {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(mutex);
            cv.wait(lock, [this]
            {
                return stop || !tasks.empty();
            });
            if (stop && tasks.empty())
            {
                return;
            }
            task = std::move(tasks.front());
            tasks.pop();
        } 
        task();
    }
}
void ThreadPool::submit(std::function<void()> task)
{
    {
        std::lock_guard<std::mutex> guard(mutex);

        tasks.push(std::move(task));
    }
    cv.notify_one();
}
ThreadPool::~ThreadPool()
{
    {
        std::lock_guard<std::mutex> guard(mutex);

        stop = true;
    }

    cv.notify_all();

    for (auto& th : workers)
    {
        if (th.joinable())
        {
            th.join();
        }
    }
}