echo "hello" `whoami`
echo "today is" `date`
echo "you've been working `uptime --pretty`" 

# information
alias ver="lsb_release -a"
alias verboost="cat /usr/include/boost/version.hpp | grep BOOST_LIB_VERSION"
alias username="echo $USER"
alias fcount="ls | wc -l"
alias count="wc -l"
alias ocount="find . -type f -name \"*.o\" | wc -l"
alias gcclist="ls /usr/bin | grep g++-"
alias myip2="hostname -I"
alias myip="ifconfig | ack -o \"inet .* netmask\" | sed \"s/netmask//g\""
alias links="ls  -l --no-group | cat | ack -o \"[0-9]{2}:[0-9]{2}.* -> .*$\" | sed \"s/^......//g\""
alias ports="sudo lsof -i -P -n | grep LISTEN"
alias userlist="cat /etc/passwd | grep -o -P \"^.*?:\" | sed \"s/:$//g\" | sort"
alias mysys="./~/system_info"

# file information
alias bytes="stat --print=%s "
alias filesize="ls -l --block-size=MB "
alias dirsize="du -sh "

alias findps="ps -eo comm,pid | ack -i "
alias findlib="ldconfig --print-cache | ack -i "
alias findfile="find ~ -type f -name "
alias findhere="find . -type f -name "
alias finddir="find ~ -type d -name "

alias en="~/./en en-pl"
alias pl="~/./en pl-en"
alias fromname="/home/$(whoami)/./fromname"
alias system_info="/home/$(username)/./system_info"

# git
alias back="git checkout ."
alias unstage="git reset HEAD ."
alias gitc="git checkout"
alias gitl="git log"
alias backcommit="git reset --soft HEAD~1"
alias backcommit2="git revert HEAD"
alias gg="git gui &"
alias lastcom="git log --pretty=format:'%h' -n 1 | cat"
alias remotename="git remote -v"
alias gitls="git ls-files"
alias whenadded="git log --diff-filter=A -- "
alias gitfind="git ls-files | ack -i "
alias filehis="git log --follow -p -- "

alias aliases="less ~/.zshrc | ack -o \"^alias.*$\" | sed \"s/alias //g\" | nl"
alias aliases-edit="gedit ~/.zshrc &"
alias aliasesgit="aliases | ack git"

# search package
alias fromlist="dpkg --get-selections | cut -f1 | ack -i "
alias fromlist2="dpkg --list | ack -i "
alias fromnet="apt-cache search "

alias inst="sudo apt-get install"
alias instf="sudo apt-get --ignore-missing install "
alias instver="sudo apt-get install program name="
alias rem="sudo dpkg --remove "
alias remf="sudo dpkg --remove --force-depends "
alias remff="sudo dpkg --purge "
alias remgroup="echo 'rem \$(fromlist boost)' && echo 'remf \$(fromlist boost)'"

alias debi="sudo dpkg --install "
alias debr="sudo dpkg --remove "
alias debinfo="dpkg --status "
alias debvers="sudo apt-cache policy "
alias debfiles="dpkg --listfiles "
alias debfile="dpkg --search "
alias debload="apt-get -d -o dir::cache=$HOME -o Debug::NoLocking=1 install "
alias debhere="sudo dpkg --install --instdir=. "

alias netb="~/netbeans-8.2/bin/./netbeans &"

alias tarex="tar --extract "
alias tarshow="tar --list -f "
alias zipshow="unzip -l "

alias debugger="gdb --args "
alias setg++49="sudo unlink /usr/bin/g++ && sudo ln -s /usr/bin/g++-4.9 /usr/bin/g++ && g++ --version"
alias setg++8="sudo unlink /usr/bin/g++ && sudo ln -s /usr/bin/x86_64-linux-gnu-g++-8 /usr/bin/g++ && g++ -v"

