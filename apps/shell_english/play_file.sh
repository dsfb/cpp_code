#!/bin/bash

# an instruction
# 1) install g++ downloading MinGW Installation Manager
# 2) give a permission to a script
# chmod u+x play_file.sh
# make some directories
# cd /mnt/c && mkdir code && mkdir en_audio && cd code
# 3) clone reposytory with git clone
# 4) run cmd and compile an app
# g++ C:\\code\cpp_code\shell\play_mp3.cpp -o C:\\en_audio\play.exe -lWinmm
# alias enp='/mnt/c/code/cpp_code/shell/./play_file.sh'
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

echo "playing a file: $1"
echo "the file has $line_count lines"
echo "an audio folder size: `du -h $audio_folder`"
sleep 1

while [ $current_line -le $line_count ]
do
    # get a next line
    cd $start_folder
    line=`cat $1 | sed -n ${current_line}p`

    # remove useless symbols
    original_line=$line
    line=`echo $line | tr '.' ' '` # dots
    line=`echo $line | tr ',' ' '`
    line=`echo $line | sed 's/|.*|//g'` # pipes
    line=`echo $line | sed 's/(.*)//g'` # braces
    line=`echo $line | sed 's/smth/something/g'` # something
    line=`echo $line | sed 's/smb/somebody/g'` # somebody
    line=`echo $line | sed 's/sb/somebody/g'` # somebody
    line=`echo $line | cut -d- -f1` # first part

    # compute a word count
    word_count=`echo $line | wc --words`

    # get file names
    audio_file=""
    index=0
    word_number=1
    while [ $word_number -le $word_count ]
    do
        audio_file[index]=`echo $line | cut -d' ' -f${word_number}`
        let word_number++
        let index++
    done

    # testing
    #echo "file names = ${audio_file[*]}"
    #echo "line = $line"
    #echo "word count = $word_count"; echo ""
    #let current_line++
    #sleep 1
    #unset audio_file
    #continue

    # pick a current folder
    cd $audio_folder

    # a loop for downloding audio files
    for file in "${audio_file[@]}"
    do
        # if there is no such file
        if [ ! -f "$file.mp3" ]
        then
            wget --quiet https://wooordhunt.ru/data/sound/word/us/mp3/$file.mp3
        fi
    done
    
    clear

    # show a line and print a line number
    echo $original_line
    echo ""; echo "$current_line / $line_count"

    # a loop for playing sounds
    for file in "${audio_file[@]}"
    do
        ./play.exe "$file.mp3"
    done

    unset audio_file
    let current_line++
    sleep 2
done

exit 0