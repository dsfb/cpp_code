# how to install g++ compiler
sudo apt-get update

# to find some g++ or gcc compiler version
sudo apt-cache search g++ | grep "g++-8"

# pokazać info dotyczące owego pakietu
apt-cache show g++-8

# installation
sudo apt-get install g++-8 # cpp-compiler
sudo apt-get install gcc-8 # c-compiler

# linking (tworzę skrót o nazwie g++, z którego korzystają środowiska)
cd /usr/bin
sudo rm g++ # if exist
sudo ln -s g++-8 g++

# how to test
whereis g++
file g++
g++ --version

# where installed g++ files
sudo dpkg -L PACKAGE_NAME


***


