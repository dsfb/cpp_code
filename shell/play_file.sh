#!/bin/bash

if [ ! -e ~/en_audio ]
then
    mkdir ~/en_audio
fi

line_count=`cat $1 | grep -v ^$ | wc --lines`
current_line=1
audio_file=""
old_pwd=`pwd`

echo "playing a file: $1"
echo "a file has $line_count lines"
echo "a folder with audio: `du -h ~/en_audio`"
echo ""

#echo `cat $1 | sed -n 1p`
#echo $ "line count: $line_count"

while [ $current_line -le $line_count ]
#while [ $current_line -le 2 ]
do 
    file_name_part_one=`cat $1 | sed -n ${current_line}p | cut -d- -f1`
    file_name__withount_pipes=`echo $file_name_part_one | sed 's/|.*|//g'`
    file_name__withount_braces=`echo $file_name__withount_pipes | sed 's/(.*)//g'`
    audio_file[0]=`echo $file_name__withount_braces | cut -d' ' -f1`
    audio_file[1]=`echo $file_name__withount_braces | cut -d' ' -f2`
    audio_file[2]=`echo $file_name__withount_braces | cut -d' ' -f3`
    audio_file[3]=`echo $file_name__withount_braces | cut -d' ' -f4`
    audio_file[4]=`echo $file_name__withount_braces | cut -d' ' -f5`
    echo ${audio_file[*]}
    #continue;

    #if [[ $string == *"My long"* ]]; then
        #echo "It's there!"
    #fi

    if [ ! -f "~/en_audio/${audio_file[0]}.mp3" ]
    then 
        cd ~/en_audio
        wget --quiet https://wooordhunt.ru/data/sound/word/us/mp3/${audio_file[0]}.mp3
        cd $old_pwd
    fi
    if [ ! -f "~/en_audio/${audio_file[1]}.mp3" ]
    then 
        cd ~/en_audio
        wget --quiet https://wooordhunt.ru/data/sound/word/us/mp3/${audio_file[1]}.mp3
        cd $old_pwd
    fi
    if [ ! -f "~/en_audio/${audio_file[2]}.mp3" ]
    then 
        #echo "https://wooordhunt.ru/data/sound/word/us/mp3/${audio_file}.mp3"
        cd ~/en_audio
        echo "downloading an audio"
        wget --quiet https://wooordhunt.ru/data/sound/word/us/mp3/${audio_file[2]}.mp3
        cd $old_pwd
    fi
    if [ ! -f "~/en_audio/${audio_file[3]}.mp3" ]
    then 
        #echo "https://wooordhunt.ru/data/sound/word/us/mp3/${audio_file}.mp3"
        cd ~/en_audio
        wget --quiet https://wooordhunt.ru/data/sound/word/us/mp3/${audio_file[3]}.mp3
        cd $old_pwd
    fi
    #echo "file = $audio_file"
    #file  "~/en_audio/${audio_file}.mp3"
    
    play ~/en_audio/${audio_file[0]}.mp3 
    if [ "${audio_file[0]}" != "${audio_file[1]}" ]
    then
        play ~/en_audio/${audio_file[1]}.mp3 
    fi
    if [ "${audio_file[1]}" != "${audio_file[2]}"  ]
    then
        play ~/en_audio/${audio_file[2]}.mp3 
    fi
    if [ "${audio_file[2]}" != "${audio_file[3]}"  ]
    then
        play ~/en_audio/${audio_file[3]}.mp3 
    fi

    #echo `cat $1 | sed -n ${current_line}p | cut -d- -f1 ` 
    #xterm -e "bash -c \"play ~/en_audio/${audio_file}.mp3 && exit; exec bash\"" &
    let current_line++
    #clear
    sleep 1
    #kill $(jobs -p)
    #exit 0
done


# how to set up
# 1) install a player
# inst mpg123 
# inst sox libsox-fmt-all
# 2) give a permissions
# chmod u+x play_file.sh