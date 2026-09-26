#include<iostream>
#include<mutex>
#include<thread>
#include<atomic>
#include<chrono>
int main()
{
    int test1=0;
    int test3=0;
    std::atomic<int>test2{0};
    std::mutex m;
    auto start1 = std::chrono::steady_clock::now();
    std::thread t1([&test1]
    {
        for(int i=0;i<10000;i++)test1++;
    });
    std::thread t2([&test1]
    {
        for(int i=0;i<10000;i++)
        {
            test1++;
        }
    });
    t1.join();
    t2.join();
    auto end1 = std::chrono::steady_clock::now();
    auto cost1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);
    auto start3 = std::chrono::steady_clock::now();
    std::thread t3([&]
    {
        for(int i=0;i<10000;i++)
        {   
            std::lock_guard<std::mutex>guard(m);
            test3++;
        }
    });
    std::thread t4([&]
    {
        for(int i=0;i<10000;i++)
        {
            std::lock_guard<std::mutex>guard(m);
            test3++;
        }
    });
    t3.join();
    t4.join();
    auto end3 = std::chrono::steady_clock::now();
    auto cost3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3);
    auto start2 = std::chrono::steady_clock::now();
    std::thread t5([&]
    {
        for(int i=0;i<10000;i++)
        {
            test2++;
        }
    });
    std::thread t6([&]
    {
        for(int i=0;i<10000;i++)
        {
            test2++;
        }
    });
    t5.join();
    t6.join();
    auto end2 = std::chrono::steady_clock::now();
    auto cost2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);
    std::cout<<"test1(无锁int) 结果:"<<test1<<" 耗时:"<<cost1.count()<<" us\n";
    std::cout<<"test2(atomic)   结果:"<<test2<<" 耗时:"<<cost2.count()<<" us\n";
    std::cout<<"test3(mutex)    结果:"<<test3<<" 耗时:"<<cost3.count()<<" us\n";
}