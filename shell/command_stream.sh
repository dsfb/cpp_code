sd[a-z] = solid disk + symbol
/proc # there are indentifiers of runned proceses

0	#stdin	Standard input
1	#stdout	Standard output
2	#stderr	Standard error

# the information about system
hostname # name of your host
whoami # who am I?
who --count # who is logged in
uname -a # what is your operation system?
groups # shows you which groups you are a member
id # your id

# set new ssh key
ssh-keygen -t rsa -b 4096 -C "email or your name"
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_rsa

find . -type l # find links here
find . -type d # find all folders here
find . -type f -not -name "*.cpp" # all files but *.cpp
find ~ -type f -name "*.h" 2>/dev/null # without errors 

# LIBRARY AND PROCESS INFORMATION
export LD_LIBRARY_PATH=$LD_LIBRARY_PATHone:two:three # several pathes for libraries
ldd <*.so or executable> | grep not # do you need something? (undefined symbol detection)
nm --undefined-only <*.so or *.o> # external symbols
# which library's functions does your application call?
ltrace <program name>
ltrace --library <name> <program name> 
pmap <process id> # shows you memory usage of some process

# DEAMON
service --status-all # status of services
systemctl edit <deamon> --full # edit configuraion file
systemctl --host user_name@host_name <command> # change some remote daemon 
systemctl -l # all deamons
systemctl -l --state running # all runned deamons
systemctl -l --state running --type service # all runned services
systemctl daemon-reload  <daemon name> # to reload the configuration file of a deamon
systemctl list-units --type service # list of active services
systemctl list-units --type service --all # all your services
systemctl --user restart <deamon name> # restart user's deamon
systemctl is-active name.service
journalctl --user-unit name.service -n 1000  | grep "Main process exited" -B 4
pkg -l | grep -E "one|two|three" # how to find some package by name

# set up the *.service file to restart automatocally after the crash
[Service]
Restart=always

#  SOURCE OF PACKAGES
cd /etc/apt/sources.list.d
cat sources.list
deb [trusted=yes] http://xxx.xxx.xxx.xxx:xxxx/ dir1 dir2/dir3

# packages
apt-cache search <package name> # find package
apt-cache show <package name> # remote package info
apt-cache depends <package name> # which packages does uor package depend?
apt-cache rdepends <package> # kto zależy od naszego pakietu?
apt-cache policy <package name> # displays available versions of a package
apt-cache madison <package name>  # displays available versions of a package
apt-cache search <package name> # search
dpkg --status <package name> # status + information about some package
dpkg --list # all installed packages
dpkg --listfile <package name> # .deb's files
dpkg --search <file name> # in which installed package does the file exist
dpkg -I <*.deb file> # information about *.deb package
dpkg-reconfigure tzdata
apt-get install <program name>=<some version> # install some version
apt-get --only-upgrade install <package name> # upgrade one package
apt-get install <package name> # install
apt-get remove <package name> # only this package without dependencies
apt-get autoremove <package name> # remove with dependencies
apt-file show <package name> # shows you files that a package has
aptitude  # to install packages (q for exit)

ls  -l --no-group # shows links
ls -X # sort by files' extention
ls | rev | sort | rev # print files by type
ls -1 # print files one line
ls -t -1 -l -r # last modifield files are on bottom
-r reverse a result
-l long list + links
-1 one file at line
-t sort by time

psql -d coś_tam -U postgres -w -c "COPY (__TU_WKLEIĆ_ZAPYTANIE__) TO STDOUT WITH CSV HEADER " > plik.csv
cat  <file name>  | awk -F "-"  '{print $2 " - " $1}' # flip=revert columns
cut -d '-' -f2 # cut off the second column

grep
-i          # ignore case
-B <amount> # before
-A <amount> # after
-C <amount> # before and after

free -m # check your memory in megabytes
df -h # check your disks' free memory
df -h | grep 'sd[a-z]' # sd = solid disk? hard drive's free space
sudo fdisk -l | grep "sd[a-z]" # solid disks' free spaces
du ~ --max-depth=1 -h # check folder' sizes in current directory
du <file name> -h # check file size
htop # process information

id # my user and groups
sudo cat /etc/shadow | grep `whoami` # password hashes
cat /etc/passwd | grep `whoami` # current user information
passwd # how to change the password


cat /etc/group | grep `whoami`
sudo adduser <user name>

ps # terminal proceses
ps --user=`whoami` # user processes
pstree

jobs # processes was created in terminal
jobs -l # more information about jobs
bg %<job number> # move to the background and run
fg %<job number> # bring the process to the foregraund and run
ctrl+z  # suspend and move to the foreground
ctrl+c # terminate process
kill <sygnal> <job number or process id>
kill -STOP %<job number> # freeze process
kill -CONT %<job number> # contunue running (after ctrl+z)
kill -SIGTERM %<job number> # please, terminate this process
lsof # what files the system works now

inst apache2
http://127.0.0.1/ # apache main page address
/var/www/html/index.html # the main page is located here
curl localhost # port 80, test local site



# SHOW REMOTE GUI
ssh -X # x11 protocol to show remote giu on your desctop
ssh -X <address> -p <port>
~ nautilus # run remote nautilus 

ssh <alias> "import -window root" > ~/image.png

# SYSTEM LOG
tail /var/log/syslog # system log

# PORTS
sudo netstat -tulpn | grep 80
-t # tcp
-u # udp
-l # listening

# add library's path
cd /etc/ld.so.conf.d
touch lib.conf
echo "the path to your library" > lib.conf
sudo ldconfig

# TEXT EDITING
wc # word, line, char count
tr # remove or translate symbol
tr --truncate-set1 A-z a-z
tr -d 'l' # remove 'l' everywhere
tr -r 'a' # aaa -> a
split # split a file into pieces
uniq # remove the same lines ONLY IF lines are next to each other
head/tail # prints 10 line by default
tail --follow # update file's data
sort <file> 
paste # combite lines as one line
nl # number lines
join # combine files with help of the sane field
od # format text as hex,oct,dec etc
fmt # format some test
fmt -w 100 <file> # format text by wide
expand # convert tab symbols to spaces
unexpand

# environment and local variables
set # shows you all variables and functions
env # variables global
alias addpath="PATH=$PATH:." # adds current path to PATH
export name=value # creates global, environment variable
export <variable name> # convert local to gloabal variable
unset <variable name> # remove ANY variable
echo $USER
echo $HOME
echo $OLDPWD

# WILDCARDS
* # match any count of characters
? # one character
touch {1,2,3}.txt # array. creates three files
^$ # start and end of line
\'

# regular expressions
^$      # beginning and the end of line
*       # 0 or more
+       # 1 or more
?       # 0 or one (optional)
.       # exactly one except new line
{x}     # exactly x symbols
{a,b}   # range: from a to b
\.      # simple dot symbol
\n      # new line
\t      # tab
\d      # digit
\s      # space
\w      # word character (like [a-zA-Z])
[]      # some ranges or expected symbols
[0-9]   # all digits like \d
[a-z]   # range: from a to z like \w
[abc]   # a,b or c
[^abc]   # not abc
()      # group
|       # logical 'or'
(|)     # group with "or"

(^\w|\w$)   # matches the first or last line symbol
[0-9]{2,}   # matches 2+ digits 
^[0-9]{3}$  # matches exactly 3 digits
[a-z0-9_]   # a-z, 0-9 and underscore

# repeate patterns
.{1}    # exactly one times
.*      # 0 or more times   
.+      # 1 or more times
.?      # 0 or one

ps -a # select all processes
ps -p <process id>
ps -u `whoami` # there are my processes

nslookup <site name> # get name server of some web site
nmap -F localhost # fast scan your opened ports
nmap -p <port> # scans specific port
nmap -p 80,20-30
nmap -A <address>
nmap -sT # scan tcp
nmap -p T:80 # is it tcp?

netstat -r  # shows local route
netstat -i # interfaces
netstat -ie # interfaces with extend information
netstat --interfaces
netstat --interfaces --extend
netstat -c # stream
netstat -a | less # all connections
netstat -a -t  # all tcp
netstat -a -t -l # all tcp with status LISTEN
netstat  -t -l -p # with program id or name
netstat -t -n # tcp with numeric ports
history | tail -n 40 | sed "s/^......//g"

netcat <address> <port> # test connection
netcat -zv 127.0.0.1 1-80 # scan this port range fron 1 to 80
netcat -l -p <port number> # now netcat is listening port
netcat -lvp <port> > <file name> # wrote data to a file
netcat -lvp <port> -e <shell or script file> # share port for remote control
netcat -lvp <port> -e cmd.exe # windows remote control
netcat -lvp <port> -e /bin/bash
-z # scan ports without sending any information
-v # show me more information
-e # execute somethig  


echo "tell your name"
read your_name # read local variable from std input
echo "your name is " $your_name
read me < <file name> # read the first file of file to local variable
ls > <file name> # redirrection: write to file
du -h --total --max-depth=0 ~ # size of the home directory
> # replace content
>> # append to the existed content
head -n 20 # shows 20 first lines of some file
find /usr/bin -type l | grep  \/vi$ # vi is a link to vim
xxx.xxx.xxx.xxx/24 # 24 bits for mask
sudo ifconfig <interface name> <address>/24 # set ip and netmask
!* # arguments of a previous command
wc -l # shows you how much lines it has

function name()
{
    echo $0 $1 $2 $?; # arguments and the result of last closed program
    whoami;
    uptime -p;
    pwd;
    uname -a;
    date;
}

chmod u+s <file name> # all can run file as owner
test # test files and compare values
test -e en && echo $? # file exist if ? = 0
test 5 -gt 2; echo $? # 5 greater than 2?
["text" = "text"] # compare text
test 2 -gt 1 &&  echo "yes" || echo "no"
<command1> && <command2> # runs cmd2 if previours was 0

# awk - match a pattern, split/separate a text by field and format output
# awk arguments
-F value # sets the field separator
awk '{ print }' <file name> # print all file's lines
# default awk separate by white spaces
awk '{ print $1 }' <file name> # print first column
awk '{ print $1,$2 }' <file name>
awk '{ print $1.$2 }' <file name> # combine
awk '{ /phrase/ print }' <file name> # find a phrase (case sensitive)
awk '{ if($1 ~ /value/) print }' <file name> # if $1 equals to value
# awk regular expressions and language
[a-z] # lowercase symbol
[0-9] # digit
^$ # start and end of the line
$NF # last column in a file
${NF-1} # the last but one column
~ # equals sign
!~ # doesn't equals to

fc # run previous command in an editor
mkdir -p dir1/{dir2,dir3}/dir4

# dump and unsorted
echo $PS1 # shows the prompt's pattern
echo $? # exit code of last command
echo $# # number of argumetns
echo $! # pid of last runned program in foreground 
whatis vim # what is that?
cat > <file name> # write some test to file
sudo fdisk /dev/sdb # run disk manager
mkfs .ext4 /dev/sda2 # format disk
/etc/ld.so.conf.d # additional *.conf files to find libraries

echo hi | hexdump # text to hexademical
echo hi | md5sum # get md5 hash
md5sum <file name> # check md5 message 

diff <file one> <file two> # shows a difference between files
sudo sshfs -o allow_other <remove server> <local directory>
rpm --query --all # shows all installed packages
yum install <name> # install a package
cd /etc/sysconfig/network-scripts/ # interfaces' con files
su # set user to root
ip link ls up # list all active interfaces
ip link set <interface> up/down # switch on of swiches off some interface 
tree -L 2 # until level 2
less /etc/group | grep docker # it'll show you all groups
wget -nH --cut-dirs=3 --recursive --no-parent -R "index.html*" https://host-name/dir1/dir2/ # download all folder