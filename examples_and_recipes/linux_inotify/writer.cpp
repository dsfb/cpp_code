
/*
clear && g++ writer.cpp -o writer  && ./writer
 */

#include <string>
#include <fstream>
#include <iostream>
#include <regex>
#include <list>

using namespace std;


void write_to_file()
{
    const string file_name = "file_to_observe";
    std::ofstream file_writer;

    try
    {
        file_writer.open(file_name, std::ios::out);
    }
    catch(const exception& e)
    {
        cout << e.what() << endl;
        return;
    }
    if (!file_writer.is_open())
    {
        cout << "the file wasn't open" << endl;
        return;
    }

    file_writer.write("a", sizeof("a"));
    file_writer.close();

}

int main()
{
    write_to_file();
    return   0;
}