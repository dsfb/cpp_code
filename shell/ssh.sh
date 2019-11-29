# set new ssh key
ssh-keygen -t rsa -b 4096 -C "email or your name"
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_rsa
ssh -p <port> # set port number
cd ~/.ssh && touch config && vim config
# comment in ssh
ssh xtest@<server one> -p <port> -N -L 9000:<server two>:22
ssh xtest@localhost -p 9000
ssh -X # x11 protocol to show remote giu on your desctop
ssh -X <address> -p <port>
ssh <alias> "import -window root" > ~/image.png
sudo sshfs -o allow_other <remove server> <local directory>
