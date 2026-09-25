#include<iostream>
#include<thread>
#include<mutex>
void worker()
{
    std::cout<<"worker\n";
}
int main()
{   
    std::mutex m;
    std::mutex m1;
    std::thread t(worker);
    t.join();
    std::thread t1([](int x){std::cout<<x<<'\n';},50);
    t1.join();
    //data race
    int counter=0;
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
    t2.join();
    t3.join();
    std::cout<<counter<<'\n';

}