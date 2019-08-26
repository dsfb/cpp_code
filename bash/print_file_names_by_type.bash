#!/bin/bash

echo "images/"
echo `find -type f -iname "*.png" | sed "s/^..//g"`
echo `find -type f -iname "*.jpg" | sed "s/^..//g"`
echo "music/"
echo `find -type f -iname "*.mp3" | sed "s/^..//g"`
echo `find -type f -iname "*.flac" | sed "s/^..//g"`
echo "videos/"
echo `find -type f -iname "*.mov" | sed "s/^..//g"`
echo `find -type f -iname "*.avi" | sed "s/^..//g"`
echo `find -type f -iname "*.txt" | sed "s/^..//g"`
echo `find -type f -iname "*.jpeg" | sed "s/^..//g"`
echo `find -type f -iname "[0-9]*" | sed "s/^..//g"`
