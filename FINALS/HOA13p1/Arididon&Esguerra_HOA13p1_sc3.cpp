#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

int total = 0;  
std::mutex mtx; 

void add(int n)
{

    std::this_thread::sleep_for(std::chrono::milliseconds(n * 10));
    std::lock_guard<std::mutex> lock(mtx);
    total += n;
}

int show()
{
    std::lock_guard<std::mutex> lock(mtx);
    return total;
}

int main()
{
    std::thread t1(add, 10);
    std::thread t2(add, 20);
    std::thread t3(add, 30);

    std::cout << "Display             : " << show() << std::endl;
    t1.join();
    std::cout << "After T1.join()     : " << show() << std::endl;
    t2.join();
    std::cout << "After T2.join()     : " << show() << std::endl;
    t3.join();
    std::cout << "After T3.join()     : " << show() << std::endl;
    return 0;
}
