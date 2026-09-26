#include<condition_variable>
#include<mutex>
#include<queue>
#include<thread>
#include<iostream>
int main()
{
    std::condition_variable cv;     
    std::mutex m;
    std::queue<int>q;
    std::thread worker([&]
    {   int task;
        for(int i=0;i<10;i++)
        {
            {
                std::unique_lock<std::mutex>lock(m);
                cv.wait(lock,[&]
                {
                    return !q.empty();
                });
                task=q.front();
                q.pop();
            }
            std::cout<<"processing:"<<task<<'\n';
        }
    });
    for(int i=0;i<10;i++)
    {
        {   
            std::lock_guard<std::mutex>guard(m);
            q.push(i);
        }
        cv.notify_one();
    }
    worker.join(); 
}