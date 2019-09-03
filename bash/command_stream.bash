HEAD - ostatni commit
HEAD^ - przedostatni 
HEAD^^ - jeszcze głębiej
HEAD^^..HEAD - zakres 
HEAD~2 = HEAD^^
HEAD~1 = HEAD^
HEAD~0 = HEAD

# all git configurations
git config --global --list (-l)

# set new ssh key
ssh-keygen -t rsa -b 4096 -C "email or your name"
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_rsa

find . -type l # find links here
find . -type d # find all folders here
find . type -f -not -name "*.cpp" # all files but *.cpp
