# secure shell

ssh -V # shows you a program version

ssh -p <port> # set port number
cd ~/.ssh && touch config && vim config
ssh xtest@<server one> -p <port> -N -L 9000:<server two>:22 # tunnel
ssh xtest@localhost -p 9000
ssh -X # x11 protocol to show remote giu on your desctop
ssh -X <address> -p <port>
ssh <alias> "import -window root" > ~/image.png # make screeshot
sudo sshfs -o allow_other <remove server> <local directory>


# set new ssh key
ssh-keygen -t rsa -b 4096 -C "email or your name"
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_rsa
~/.ssh/id_rsa.pub # my local public ssh key
~/.ssh/id_rsa # my own private key
ssh-copy-id user@server - to copy a public key to remote machine
ssh-copy-id '-p 8888 user@server' - copy key by using unusual port
less ~/.ssh/known_hosts - hosts when i know
ssh-keygen -R <server> - remove remote key from local machine

EXECUTE COMMANDS
ssh <user name>@<address> - an ordinary connection to remote machine
ssh <user name>@<address> -p <port> - connect to remote with a port
ssh <user name>@<address> "<command>" - execute a command and disconnect
ssh <user name>@<address> "<command>" > <result file path> - execute command and save a result on local machine
ssh <user name>@<address> "<command>" | <local program> - send result into a pipe

COPY FROM OR TO
scp <from> <to>
scp -r <user name>@<address>/<remote path> <local path> - copy folder from remote to me
ssh user@<address> <command>   >   <local file> - save a result as file on local machine
<command> | scp <user name>@<address>:<file path> - write a result as file on remote machine

SSH: TO FUSE TOGETHER 
sshfs <remote address>:<path> <local path> - allow to mount a remote path like a local path
sshfs <remote address>:<path> /media/`whoami`/<device name> 
fusermount -u <path> - disconnect from remote
sudo umount -f <path> - force disconnect

SSH FUSE ARGUMENTS
-o reconnect - try to reconnect without an error
-o idmap=user - allow to work like another user

ALIASES
man ssh_config - a help
touch ~/.ssh/config # list of ssh aliases
vim ~/.ssh/config

# write it to the file ~/.ssh/config
# this is comment in ssh configuration file
Host <alias name>
HostName <your ip addesss like xxx.xxx.xxx.xxx>
User <user name>
Port 22
IdentityFile ~/.ssh/<your custom ssh private key>
