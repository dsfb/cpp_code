qmake -project - creates *.pro file in current directory adding all source file from `ls`
qmake file.pro -о Makefile - creates make_file from .pro file
qmake - finds .pro file and generage MakeFile
moc -о file.moc main.h - tworzy .moc file

project.pro file descrition:
CONFIG =+ debug - równa się `g++ -g source.cpp`


pkg-config --cflags protobuf - get g++ flags to include *.h files
pkg-config --libs protobuf - get g++ flags to include *.a or *.so files from Linux package



g++ -g -o PROGRAM_NAME main.c - compile with debug information
objcopy --only-keep-debug main main.debug - separate the debug information

or

cp main main.debug
strip --only-keep-debug main.debug

Strip debug information from origin file:

objcopy --strip-debug main

or

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
