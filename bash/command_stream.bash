HEAD - ostatni commit
HEAD^ - przedostatni 
HEAD^^ - jeszcze głębiej
HEAD^^..HEAD - zakres 
HEAD~2 = HEAD^^
HEAD~1 = HEAD^
HEAD~0 = HEAD

# run meld and start the megring process
git config --global diff.tool meld
git config --global merge.tool meld
git config --global --add difftool.prompt false # wtf?
meld . 

git config --global core.excludesfile ~/.gitignore # set global git-ignore file
git config --global core.editor "vim"  # set vim as main text editor
git config --global --list (-l)     # all git configurations
git checkout <commit hash> <file name> # cofąć plik do stanu jakiegoś comita
git add . && git commit -m "update" && git push

# set new ssh key
ssh-keygen -t rsa -b 4096 -C "email or your name"
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_rsa

find . -type l # find links here
find . -type d # find all folders here
find . -type -f -not -name "*.cpp" # all files but *.cpp

export LD_LIBRARY_PATH=one:two:three:four # several pathes for libraries
ldd <*.so or executable> | grep not # do you need something? (undefined symbol detection)
nm --undefined-only <*.so or *.o> # external symbols
# which library's functions does your application call?
ltrace <program name>
ltrace --library <name> <program name> 

journalctl --user-unit name.service -n 1000  | grep "Main process exited" -B 4
pkg -l | grep -E "one|two|three" # how to find some package by name

cd /etc/apt/sources.list.d
deb [trusted=yes] http://xxx.xxx.xxx.xxx:xxxx/ dir1 dir2/dir3
apt-get install <program name>=<some version>
usctl restart panel1 

ls -X # sort by file's extention
ls | rev | sort | rev # print files by type
ls -1 # print files one line
ls -t -1 -l -r # last modifield files on bottom
-r reverse
-l long list
-1 one file at line
-t sort by time

psql -d coś_tam -U postgres -w -c "COPY (__TU_WKLEIĆ_ZAPYTANIE__) TO STDOUT WITH CSV HEADER " > plik.csv
cat  <file name>  | awk -F "-"  '{print $2 " - " $1}' # flip=revert columns
cut -d '-' -f2 # cut off the second column
