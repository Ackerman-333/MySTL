#include<mutex>
#include<iostream>
#include<thread>
int main()
{
    std::mutex m;
    std::mutex m1;
    //data race
    int counter=0;
    int counter1=0;
    int local=0;
    std::thread t2([&]{
        for(int i=0;i<10000;i++)
        {
            std::lock_guard<std::mutex>guard(m);
            counter++;
        }
    });
    std::thread t3([&]{
        for(int i=0;i<10000;i++)
        {
            std::lock_guard<std::mutex>guard(m);
            counter++;
        }
    });

    std::thread t4([&]{
        for(int i=0;i<10000;i++)
        {
        local++;
        }
        std::lock_guard<std::mutex>guard(m1);
        counter1+=local;
    });
        std::thread t5([&]{
        for(int i=0;i<10000;i++)
        {
        local++;
        }
        std::lock_guard<std::mutex>guard(m1);
        counter1+=local;
    });
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    std::cout<<counter<<'\n';
    std::cout<<counter1;
}