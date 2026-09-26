#include "../include/thread_pool.hpp"
#include <iostream>
#include <chrono>
int main()
{
    ThreadPool pool(4);
    for (int i = 0; i < 10; ++i)
    {
        pool.submit([i]
        {
            std::cout
                << "processing task "
                << i
                << '\n';

            std::this_thread::sleep_for(
                std::chrono::milliseconds(100)
            );
        });
    }
    return 0;
}