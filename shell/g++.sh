# is g++ compiler intalled?
whereis g++
file g++
g++ --version

# where g++ files was installed
sudo dpkg --listfiles <package name>

# the installation process
sudo apt-get install g++-8 # cpp-compiler
sudo apt-get install gcc-8 # c-compiler

# to change the version of g++ with a new link
cd /usr/bin
sudo rm g++ # remove if it exists
sudo ln -s g++-8 g++

# g++ arguments
-ggdb or -g - to generate debugging information 
-std=c++17 - określa standard C++
-Wall - to show all warnings
-Wextra - to show extra warnings
-I - określa miejsce gdzie można znaleźć header files np. -Iinclude
-L - na przykład -Lname szuka biblioteki w folderze ./name
-l - na przykład -lNAME szuka libary o nazwie libNAME.a
-o - zapisać coś i gdzieś np. -o src/file.o strorzy plik i zapisze go w folderze src
-o - skompilować jako binarny plik np. -o bin/EXECUTABLE
-c - skompilować plik *.cpp i jako *.o (an object file
-g - dodaje debug informacje poziomu 2
-g3 - dodaje dedugging information o poziomie 3, zawierające macro definitions
-Og - optymizacja kodu dla debug celów; it does not collect debug information
-m32 - compile x32 bit prorgam on x64 OS version

qmake -project - creates *.pro file in current directory adding all source file from `ls`
qmake file.pro -о Makefile - creates make_file from .pro file
qmake - finds .pro file and generage MakeFile
moc -о file.moc main.h - tworzy .moc file

project.pro file descrition:
CONFIG =+ debug - równa się `g++ -g source.cpp`


pkg-config --cflags protobuf - get g++ flags to include *.h files
pkg-config --libs protobuf - get g++ flags to include *.a or *.so files from Linux package


g++ -g -o PROGRAM_NAME main.c - compile with debug information

# separate the debug information
objcopy --only-keep-debug main main.debug
cp main main.debug && strip --only-keep-debug main.debug

# to strip debug information from origin file
strip <binary file>
g++ -s
objcopy --strip-debug <binari file>
strip --strip-debug --strip-unneeded main

debug by debuglink mode:

objcopy --add-gnu-debuglink main.debug main
gdb main

You can also use exec file and symbol file separatly:

gdb -s main.debug -e main

or

gdb
(gdb) exec-file main
(gdb) symbol-file main.debug

For details:

(gdb) help exec-file
(gdb) help symbol-file
# how to install g++ compiler
sudo apt-get update

# to find some g++ or gcc compiler version
sudo apt-cache search g++ | grep "g++-8"

# pokazać info dotyczące owego pakietu
apt-cache show g++-8









