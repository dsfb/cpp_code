/* 
I train to use std::mutex, std::thread, std::async and try to
get data race 

Aleksander Czastuchin
2019, summer
$ g++ -std=c++17 cpp11_thread_and_async.cpp -o main.exe && ./main.exe
*/
#include <cstdio>
#include <thread>
#include <future>
#include <vector>
#include <chrono>

using std::thread;
using std::vector;
using std::thread;
using std::mutex;
using std::chrono::duration;
using type = unsigned;

bool do_somethig(const bool arg)
{
    printf("inside do_something() function\n");
    //std::this_thread::sleep_for(1000);
    return arg;
}

void async_test()
{
    using std::async;
    using std::future;
    future f = async(do_somethig, true);
    f.wait(); // wait for the and of do_something()
    printf("%i\n", f.get());
}

void parallel_incrementation()
{
    type change_me = 0;
    vector<type> results;
    vector<thread> threads;
    mutex sharing;

    auto change_function = [&](){
        //printf("inside change_function()\n");
        
        while (change_me < 10) {
        std::lock_guard<mutex> guard(sharing);
        results.push_back(++change_me);
        //std::chrono::milliseconds ms{change_me};
        //std::this_thread::sleep_for(ms);
        }
    };

    for(short i = 0; i < 5; i++)
    {
        threads.emplace_back(change_function);
        threads.back().detach();
    }

    //printf("\n");

    for (const auto& element : results) {
        printf("%i\n", element);
    }
}


int main()
{
    //async_test();
    parallel_incrementation();

    char a;
    gets(&a);
    return 0;
}