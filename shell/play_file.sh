#!/bin/bash

# install 
# 2) give a permissions
# chmod u+x play_file.sh
# alias inst='sudo apt-get install'
# cd /mnt/c && mkdir code && cd code
# git clone
# alias enp='/mnt/c/code/cpp_code/shell/./play_file.sh'
# run cmd and compile an app
# g++ C:\\code\cpp_code\shell\play_mp3.cpp -o C:\\en_audio\play.exe -lWinmm
# enp /mnt/c/code/english_language/words/words_1.txt

clear
audio_folder="/mnt/c/en_audio"
start_folder=`pwd`

if [ ! -e  $audio_folder ]
then
    mkdir $audio_folder
fi

line_count=`cat $1 | grep -v ^$ | wc --lines`
current_line=1
audio_file=""

echo "playing a file: $1"
echo "the file has $line_count lines"
echo "an audio folder size: `du -h $audio_folder`"
echo ""

#echo `cat $1 | sed -n 1p`
#echo $ "line count: $line_count"

function replace()
{
    #echo "replace " $1
    $1="bla"
    #$1=`echo $1 | sed 's/smb/somebody/g'`
}

while [ $current_line -le $line_count ]
#while [ $current_line -le 2 ]
do 
    cd $start_folder
    line=`cat $1 | sed -n ${current_line}p`
    line=`echo $line | tr ',' ' '`
    #line=`echo $line | tr 'smth' 'something'`
    #replace "$line"
    file_name_part_one=`echo $line | cut -d- -f1`
    file_name__withount_pipes=`echo $file_name_part_one | sed 's/|.*|//g'`
    file_name__withount_braces=`echo $file_name__withount_pipes | sed 's/(.*)//g'`
    audio_file[0]=`echo $file_name__withount_braces | cut -d' ' -f1`
    audio_file[1]=`echo $file_name__withount_braces | cut -d' ' -f2`
    audio_file[2]=`echo $file_name__withount_braces | cut -d' ' -f3`
    audio_file[3]=`echo $file_name__withount_braces | cut -d' ' -f4`
    audio_file[4]=`echo $file_name__withount_braces | cut -d' ' -f5`
    #echo ${audio_file[*]}
    #sleep 1
    #continue

    #if [[ $string == *"My long"* ]]; then
        #echo "It's there!"
    #fi

    # if there is no file
    if [ ! -f "$audio_folder/${audio_file[0]}.mp3" ]
    then 
        cd $audio_folder
        wget --quiet https://wooordhunt.ru/data/sound/word/us/mp3/${audio_file[0]}.mp3
    fi
    if [ ! -f "~/en_audio/${audio_file[1]}.mp3" ]
    then 
        cd $audio_folder
        wget --quiet https://wooordhunt.ru/data/sound/word/us/mp3/${audio_file[1]}.mp3
    fi
    #if [ ! -f "~/en_audio/${audio_file[2]}.mp3" ]
    #then 
        #echo "https://wooordhunt.ru/data/sound/word/us/mp3/${audio_file}.mp3"
        #cd $audio_folder
        #echo "downloading an audio"
        #wget --quiet https://wooordhunt.ru/data/sound/word/us/mp3/${audio_file[2]}.mp3
        #cd $old_pwd
    #fi
    #if [ ! -f "~/en_audio/${audio_file[3]}.mp3" ]
    #then 
        #echo "https://wooordhunt.ru/data/sound/word/us/mp3/${audio_file}.mp3"
        #cd $audio_folder
        #wget --quiet https://wooordhunt.ru/data/sound/word/us/mp3/${audio_file[3]}.mp3
        #cd $old_pwd
    #fi
    #echo "file = $audio_file"
    #file  "~/en_audio/${audio_file}.mp3"
    
    cd $audio_folder
    #clear
    echo $line
    #echo ""; echo "$current_line / $line_count"
    ./play.exe "${audio_file[0]}.mp3"

    if [ "${audio_file[0]}" != "${audio_file[1]}" ]
    then
        ./play.exe "${audio_file[1]}.mp3" 
    fi
    if [ "${audio_file[1]}" != "${audio_file[2]}"  ]
    then
        ./play.exe "${audio_file[2]}.mp3"
    fi
    #if [ "${audio_file[2]}" != "${audio_file[3]}"  ]
    #then
        #play ~/en_audio/${audio_file[3]}.mp3 
    #fi

    #echo `cat $1 | sed -n ${current_line}p | cut -d- -f1 ` 
    #xterm -e "bash -c \"play ~/en_audio/${audio_file}.mp3 && exit; exec bash\"" &
    let current_line++
    #clear
    sleep 2
    #exit 0
done

exit 0