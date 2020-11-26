#!/bin/bash

clear

if [ "`whereis protoc`" == "" ]
then
echo "there is no protoc compiler"
echo "use apt-get install protobuf-compiler"
fi

current_directory=`pwd`

protoc -I=$current_directory --cpp_out=$current_directory message.proto

echo "the compiled files"
ls -l *.pb.*
echo ""

echo "fire up the app"
g++ -std=c++11 app.cpp *.pb.cc -o app -lprotobuf -pthread
./app

rm *.zip
rm *.pb.h
rm *.pb.cc
rm app

zip -r protobub_test.zip . 1&>/dev/null
zipinfo *.zip