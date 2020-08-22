#!/bin/bash

#sudo apt-get update
#sudo apt-get upgrade -y

PACKAGES="sed make binutils build-essential gcc g++ bash patch gzip bzip2 perl tar cpio unzip rsync file bc \
wget gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf qt5-default libncurses5-dev w3m git mercurial \
openssh-server bc zip kazam qemu-user-static"

echo $PACKAGES
sudo apt-get install $PACKAGES -y


THIRD_PACKAGES="sublime-text"
wget -qO - https://download.sublimetext.com/sublimehq-pub.gpg | sudo apt-key add -
echo "deb https://download.sublimetext.com/ apt/stable/" | sudo tee /etc/apt/sources.list.d/sublime-text.list
sudo apt-get install $THIRD_PACKAGES -y

#sudo apt-get update
#sudo apt-get upgrade -y
#sudo apt-get autoremove -y
#sudo apt-get autoclean -y