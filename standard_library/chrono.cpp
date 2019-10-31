#include <chrono>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
using namespace std::chrono;

void print_time()
{
    const auto& now = system_clock::now();
    const auto nowc = system_clock::to_time_t(now);
    cout << put_time(std::localtime(&nowc), "%c %Z") << endl;
}

int main()
{
    print_time();
    return 0;
}