/*
this is an example of using Linux inotify library. this library can monitor files and folders. it informs us aech time a file or folder is modified or opened etc.

besides, this example uses poll() function and -1 as an argument to want for
file/directory events. the poll() function waits and stops the app until some
events are occured. -1 argument means to wait forever.

poll(&poll_request, 1, -1);

see more here
https://man7.org/linux/man-pages/man7/inotify.7.html

clear && g++ poll_inotity.cpp -o app  && ./app && rm -f app

*/
#include <sys/inotify.h>
#include <sys/poll.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <unistd.h>

using std::cout;
using std::endl;
#define nl '\n'

// this is a macro function for debugging
#define where() \
    cout << __FILE__ << ':' << __LINE__ << ':' << __func__ << endl; \


#define EVENT_SIZE (sizeof(inotify_event))
#define EVENT_BUF_LEN (1024 * ( EVENT_SIZE + 16 ))

// it also is called a file descriptor , and 'fd' is abbreviation
int inotify_descriptor = 0;
int watch_descriptor = 0;

pollfd poll_request;
bool file_is_deleted = false;

bool setup_inotify()
{
    where();
    inotify_descriptor = inotify_init1(IN_NONBLOCK);
    if (inotify_descriptor == -1)
    {
        cout << "inotify wasn't initialezed" << nl;
        cout << errno << strerror(errno) << nl;
        return false;
    }

    memset(&poll_request, 0, sizeof(pollfd));
    poll_request.fd = inotify_descriptor;
    poll_request.events = POLLIN;
    return true;
}

bool open_file_watch_descriptor()
{
    where();
    watch_descriptor = inotify_add_watch(inotify_descriptor, "/home/sasza/tests", IN_ALL_EVENTS);

    if (watch_descriptor == -1)
    {
        cout << errno << strerror(errno) << nl;
        return false;
    }

    return true;
}

int wait_for_events()
{
    where();
    // request result, number of descriptors, a time to wait for a descriptor
    const int poll_result = poll(&poll_request, 1, -1);

    // if there is an error
    if (poll_result == -1)
    {
            cout << errno << strerror(errno) << nl;
            where();
            return false;
    }

    // there are some events to read
    if (poll_request.revents & POLLIN)
    {
        where();
        return true;
    }
    return false;
}

int read_events()
{
    where();
    char buffer[EVENT_BUF_LEN] = {0};
    char* pointer = nullptr;

    // read events with the inotify descriptor
    int event_bytes = read(inotify_descriptor, buffer, sizeof(buffer));

    // if there are no events
    if (event_bytes <= 0)
    {
        cout << "there are no events to show" << nl;
        return false;
    }

    bool file_is_modified = false;
    const inotify_event* event = nullptr;
    int event_counter = 0;
    //std::string file_name;

    for(
        pointer = buffer;
        pointer < buffer + event_bytes;
        pointer += sizeof(inotify_event) + event->len
    )
    {
        event = reinterpret_cast<const inotify_event*>(pointer);
        // this is a file name size without \0 sign
        const int file_name_size = sizeof("file") - 1;

        // check if a file name is empty or has an incorrect value
        if (event->len <= 0 || event->len < file_name_size)
            continue;

        if (strncmp(&(event->name[0]), "file", file_name_size) != 0)
            continue;

        // this is a buffer to store a file name plus \0 symbol
        //char file_name_buffer[event->len + 1] = {'\0'};
        //#strncpy(file_name_buffer, &(event->name[0]), event->len);
        //#file_name = file_name_buffer;
        //if (file_name != "file")
            //continue;

        cout << endl;
        cout << "event information" << nl;
        //cout << "file_name_buffer is " << file_name_buffer << nl;
        //cout << "file_name is " << file_name << nl;
        cout << "name length is " << event->len << nl;
        //cout << "file_name size is " << file_name.size() << nl;
        cout << "#define size is " << sizeof("file") << nl;
        //cout << "sizeof(buffer) is " << sizeof(file_name_buffer) << nl; 

        if (event->mask & IN_OPEN)
        {
            cout << "IN_OPEN";
        }
        else if (event->mask & IN_CLOSE_WRITE)
        {
            cout << "IN_CLOSE_WRITE";
        }
        else if (event->mask & IN_MODIFY)
        {
            file_is_modified = true;
            cout << "IN_MODIFY";
        }
        else if (event->mask & IN_MOVE)
        {
            cout << "IN_MOVE";
        }
        else if (event->mask & IN_DELETE_SELF)
        {
            cout << "IN_DELETE_SELF";
        }
        else if (event->mask & IN_DELETE)
        {
            cout << "IN_DELETE";
        }
        else if (event->mask & IN_IGNORED)
        {
            cout << "IN_IGNORED";
            file_is_deleted = true;
        }
        else {
            cout << "unknown event " << event->mask;
        }
        event_counter += 1;
        cout << " number " << event_counter << nl;
    }

    return file_is_modified;
}

bool release_watch_descriptor()
{
    if (inotify_rm_watch(inotify_descriptor, watch_descriptor) == -1)
    {
        return false;
    }
    return true;
}

int main()
{
    if (!setup_inotify())
        return 0;

    if (!open_file_watch_descriptor())
        return 0;

    where();

    // watch a file forever
    while (true)
    {
        if (wait_for_events())
        {
            read_events();
        }
    }

    // release inotify descriptors
    release_watch_descriptor();
    close(watch_descriptor);

    return 0;
}