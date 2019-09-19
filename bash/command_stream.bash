sd = solid disk

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
git reset HEAD .  # unstage

# set new ssh key
ssh-keygen -t rsa -b 4096 -C "email or your name"
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_rsa

find . -type l # find links here
find . -type d # find all folders here
find . -type -f -not -name "*.cpp" # all files but *.cpp

# LIBRARY
export LD_LIBRARY_PATH=one:two:three:four # several pathes for libraries
ldd <*.so or executable> | grep not # do you need something? (undefined symbol detection)
nm --undefined-only <*.so or *.o> # external symbols
# which library's functions does your application call?
ltrace <program name>
ltrace --library <name> <program name> 

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

apt-get install <program name>=<some version> # install some version
apt-get --only-upgrade install <package name> # upgrade one package
apt-cache policy <package name> # displays available versions of a package
apt-cache madison <package name>  # displays available versions of a package
apt-cache search <package name> # search

ls  -l --no-group # shows links
ls -X # sort by file's extention
ls | rev | sort | rev # print files by type
ls -1 # print files one line
ls -t -1 -l -r # last modifield files on bottom
-r reverse
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
du . -h # check file sizes in current directory
htop # process information

id # my user and groups
sudo cat /etc/shadow | grep `whoami` # password hashes
cat /etc/passwd | grep `whoami` # current user information
passwd # how to change the password

# shows you which groups you are a member
groups
cat /etc/group | grep `whoami`
sudo adduser <user name>

ps # terminal proceses
ps --user=`whoami` # user processes
pstree

jobs # processes areated in terminal
jobs -l # more information about jobs
bg %<job number> # move to the background 
fg %<job number> # bring the process to the foregraund 
ctrl+z  # suspend and move to the foreground
ctrl+c # terminate process
kill -STOP %<job number> # freeze process
kill -CONT %<job number> # contunue running (after ctrl+z)
kill -SIGTERM %<job number> # please, terminate this process

inst apache2
http://127.0.0.1/ # apache main page address
/var/www/html/index.html # the main page is located here

# SSH
ssh -p <port> # set port number
scp -P <port> # set port number
scp -r -P <port>  <user name>@xxx.xxx.xxx.xxx:~/<folder name> . # copy directory (from -> to)

# SSH ALIAS
cd ~/.ssh && touch config && vim config
Host <alias name>
HostName <ip address>
User <user name>
Port <your port>
# comment in ssh
:wq

# SSH TUNNEL: LOCAL -> SERVER1 -> SERVER 2
ssh xtest@<server one> -p <port> -N -L 9000:<server two>:22
ssh xtest@localhost -p 9000

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

# damp
sudo fdisk /dev/sdb # run disk manager
mkfs .ext4 /dev/sda2 # format disk
/etc/ld.so.conf.d # additional *.conf files to find libraries
dpkg --status <package name> # status + information about some package
dpkg --list # all installed packages
dpkg --listfile <package name> # package's files
dpkg --search <file name> # in which package does the file exist