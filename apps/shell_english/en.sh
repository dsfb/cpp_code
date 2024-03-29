#!/bin/bash

# this is a small script that I used to translate words form pl to en language.
# it sends http requests and parses html code to get a translation and transcription.
# currently I don't use it anymore is down to I reworked it with python language.

clear
echo $2
#direction="en-pl"
direction=$1
limin=5 # in original request it equals to 30

#curl -s --data "query=$1&direction=en-pl&limit=3" http://getionary.pl/#action/search.act.php | grep -o '<translation>[^0-9]*</translation>' | #sed 's:translation::g' | tr -d '<>/' | head -5

#class="transcription"> |kɔːl|</span>

if [ $1 = "en-pl" ]
then
wymowa=$(curl --http1.1 --silent https://wooordhunt.ru/word/$2 | egrep -o 'transcription(.{1,20}?)</span>' | head -1 | awk -F "[<>]" '{print $2}')
echo $wymowa
fi

touch ~/enfile
curl --http1.1 --silent --data "query=$2&direction=$direction&limit=$limit" http://getionary.pl/action/search.act.php | egrep -o '<translation>[^<>]*</translation>' | sed 's;<translation>\([^<>]*\)</translation>;\1;g' | head -5 | nl > ~/enfile
cat ~/enfile

translate=$(cat ~/enfile | head -1 | grep -E -o "^.*$" | sed "s/^.*[0-9].//g")
rm --force ~/enfile

echo "$2 $wymowa - $translate" | xclip -selection c
#echo $(xclip -out -selection clipboard)
#notify-send "$2" "$(xclip -out -selection clipboard)"


# how to install this script?
# 1) sudo apt-get install curl
#cd ~
#touch en
#vim en # wpisać skrypt
#chmod +x ./en
#vim ~/.bashrc # dodać alias pl="~/./en pl-en"
#source ~/.bashrc
