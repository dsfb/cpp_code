#!/bin/bash

alias inst='sudo apt-get install'

inst gcc-8 gcc-8-multilib 
inst g++-8 g++-8-multilib
inst openjdk-8-jdk # java 8

# git and the tool for merging
inst git-all
inst meld

inst sshfs
inst redshift-gtk  # https://github.com/jonls/redshift
inst flashplugin-installer
inst pkg-config
inst vim
inst apt-file
inst cmake
inst net-tools # ifconfig
inst tree
inst mc # file manager
inst xclip
inst nmap
inst mailutils # to mail and reply
inst docker.io

inst libgmock-dev # google mock

# optional below
inst libssl1.0-dev
inst libqt5xml5
inst libboost1.65-all-dev
inst libgstreamer1.0
inst libgstreamer1.0-dev
#include <openssl/evp.h>
inst libssl-dev
inst libgstreamer1.0-dev
inst libgstreamer1.0-0
inst libltdl7
inst libltd7:i386
inst libltdl7:i386
inst libmpg123-0:i386
inst libout123-0:i386
inst libsystemd-dev
inst protobuf-compiler
inst libqhttpengine-dev
inst libopencv-imgproc-dev
inst libopencryptoki-dev
inst pkgconf libssl-dev
inst alsa-source


#####################################################
#####################################################
######################################################
	
step one
$ sudo make uninstall && make clean && back && git clean -df && ./autogen.sh && ./configure --disable-shared --with-abi=no --enable-libstdcxx-time=no --with-default-libstdcxx-abi=gcc4-compatible CXXFLAGS="-fPIC" && make && sudo make install

step two
$ nm -C -D libsimscampaign.so  | ack GetTypeName
00000000002fa940 T google::protobuf::Message::GetTypeName() const

step three
$ nm -C message.o | ack cxx11

#####################################################
#####################################################
######################################################

git clone https://github.com/nitroshare/qhttpengine.git
export Qt5Core_DIR=~/Qt5.7.1/5.7/gcc_64/lib/cmake/Qt5Core
export Qt5Network_DIR=~/Qt5.7.1/5.7/gcc_64/lib/cmake/Qt5Network
cmake .
make
make install
LIBS += -lqhttpengine # wskazuwka dla linkera, żeby szukał tej biblioteki

