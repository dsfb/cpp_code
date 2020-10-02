/*
this is an example of using Linux inotify library. this library can monitor files and filders. we can be informed after a files was changed or opened etc. 
https://man7.org/linux/man-pages/man7/inotify.7.html 

clear && g++ notify.cpp -o notify  && ./notify
*/
#include <sys/inotify.h>
#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
#include <unistd.h>

using std::cout;
#define nl '\n'

#define EVENT_SIZE (sizeof(inotify_event))
#define EVENT_BUF_LEN (1024 * ( EVENT_SIZE + 16 ))

bool check_error(const int inotify_descriptor)
{
    return inotify_descriptor == -1;
}

int main()
{
    int file_descriptor = inotify_init();
    if (check_error(file_descriptor))
        return 0;

    int watch_descriptor = inotify_add_watch(file_descriptor, "file_to_observe", IN_MODIFY);
    if (check_error(watch_descriptor))
        return 0;

    cout << "watch the file" << nl;
    char buffer[EVENT_BUF_LEN] = {0};
    while (true)
    {
        char* pointer = nullptr;
        //buffer = {0};
 
        // read an event with the inotify file descriptor
        int event_bytes = read(file_descriptor, buffer, EVENT_SIZE);

        // if there are no events
        if (event_bytes <= 0)
        {
            cout << "there are no events to show" << nl;
            continue;
        }

        pointer = buffer;
        const inotify_event* event = nullptr;
        do {
            event = reinterpret_cast<const inotify_event*>(pointer);
            pointer += sizeof(inotify_event) + event->len;

            // if a file was modified
            if (event->mask == IN_MODIFY)
                cout << "IN_MODIFY" << nl;
        }
        while (pointer < buffer + event_bytes);
    }

    inotify_rm_watch( file_descriptor, watch_descriptor );
    close(file_descriptor);

    return 0;
}