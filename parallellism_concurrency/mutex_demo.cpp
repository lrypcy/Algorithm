#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>

volatile int counter{0};
std::mutex mtx;
std::timed_mutex timed_mtx;

void attempt_10k_increases()
{
    for (int i = 0; i < 10000; ++i)
        if (mtx.try_lock())
        {
            ++counter;
            mtx.unlock();
        }
}

void test_attempt_10k_increases()
{
    std::cout << std::endl
              << "test attempt_10k_increases" << std::endl;
    std::vector<std::thread> thds(10);
    for (int i = 0; i < 10; ++i)
        thds[i] = std::thread(attempt_10k_increases);
    for (auto & th  : thds)
        th.join();
    std::cout << counter << " successful increases of the counter." << std::endl;
    return;
}

void fireworks()
{
    while (!timed_mtx.try_lock_for(std::chrono::milliseconds(200)))
        std::cout << '-';
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "*\n";
    timed_mtx.unlock();
}


void test_fireworks()
{
    std::cout << std::endl
              << "test fireworks" << std::endl;
    std::vector<std::thread> thds(10);
    for (int i = 0; i < 10; ++i)
        thds[i] = std::thread(fireworks);
    for (auto & th : thds)
       th.join();
}

int main(int argc, char **argv)
{
    test_attempt_10k_increases();
    std::cout<<("hello world")<<std::endl;
    test_fireworks();
    return 0;
}