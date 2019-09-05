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

git config --global --list (-l)     # all git configurations
git checkout <commit hash> <file name> # cofąć plik do stanu jakiegoś comita

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
pkg -l | grep -E "one|two|three"

cd /etc/apt/sources.list.d
deb [trusted=yes] http://xxx.xxx.xxx.xxx:xxxx/ dir1 dir2/dir3
