#include <string>
#include <iostream>

#include <windows.h>
#include <Mmsystem.h>

//#include <mciapi.h>
//these two headers are already included in the <Windows.h> header
//#pragma comment(lib, "Winmm.lib")

using std::string;
using std::cout;

int main(int arguments_count, char** arguments)
{
    cout << "argument[1] = " << arguments[1];
    if (arguments_count != 2)
    {
        cout << "there are not 2 arguments";
        return 0;

    }
    
    string command = "open \"";
    command += arguments[1];
    command += "\" type mpegvideo alias mp3";
    
    mciSendString(command.c_str(), NULL, 0, NULL);
    //To play and wait until the *.mp3 has finished playing:
    mciSendString("play mp3 wait", NULL, 0, NULL);
    return 0;
}

/*
https://sourceforge.net/projects/mingw/
g++ play_mp3.cpp -o play.exe -lWinmm && ./play.exe "C:\\file.mp3"
*/