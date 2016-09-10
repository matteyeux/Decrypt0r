#!/bin/bash
#######################################################################
#
#  Project......: setup.sh
#  Creator......: matteyeux
#  Description..: Script to install usefull tools for Decrypt0r
#
######################################################################
# Language :
#               bash
# Version : 0.3
#
#  Change Log
#  ==========
#	 DD/MM/YY
#   ===============================================================
#    Date     |       Who          |      What
#   ---------------------------------------------------------------
#    04/10/15 | Mathieu Hautebas   | Script creation
#   ---------------------------------------------------------------
#    10/12/15 | Mathieu Hautebas   | Added cool things
#   ---------------------------------------------------------------
#    11/12/15 | Mathieu Hautebas   | Added savethemblobs
#   ---------------------------------------------------------------
#    29/12/15 | Mathieu Hautebas   | iOS Utilities install
#   ---------------------------------------------------------------
# 	 02/01/16 | Mathieu Hautebas   | add binutils install
#   ---------------------------------------------------------------

if [[ "$(whoami)" != "root" ]]; then
    echo "Please run this script as root"
    exit 1
fi

if [[ $(uname) != 'Linux' ]]; then
  echo "This script is only for Linux"
  exit 1
fi

if [[ $(uname -m) == x86_64 ]]; then
	wget https://www.dropbox.com/s/b6m5bkaqym2gaqh/joker?dl=0 -O joker
	mv joker /usr/local/bin/
	chmod +x /usr/local/bin/joker
fi

apt-get -y install binutils
apt-get -y install p7zip-full
apt-get -y install git
apt-get -y install build-essential
apt-get -y install make
apt-get -y install cmake
apt-get -y install openssl
apt-get -y install libcrypto++-dev
apt-get -y install bsdiff
apt-get -y install libbz2-dev
apt-get -y install libpng3
apt-get -y install libusb-1.0.0
apt-get -y install libusb-1.0.0-dev
apt-get -y install libssl-dev
apt-get -y install libcurl3
apt-get -y install python-pip
cd ~
git clone https://github.com/xerub/xpwn.git
mkdir ~/build
cd ~/build
cmake ~/xpwn
make
make package
tar xvjf XPwn-0.5.8-Linux.tar.bz2

wget
cd XPwn-0.5.8-Linux
cp dmg hdutil hfsplus ipsw ticket xpwntool validate /usr/local/bin/ # Maybe I can replace this shit with one line : sudo make install 

echo "XPwn binaries installed !"


echo "Now installing reimagine..."

apt-get -y install libssl-dev:i386 #Should work for reimagine
apt-get -y install clang

cd ~
git clone https://github.com/danzatt/reimagine.git #
cd reimagine
rm -rf opensn0w-X
git clone https://github.com/danzatt/opensn0w-X.git
cd ~
cd reimagine/opensn0w-X/src && make all
cd ../.. && make

cp ~/reimagine/reimagine /usr/local/bin/

echo "Installed reimagine !"
echo "Downloading Savethemblobs..."
cd ~
git clone https://github.com/Neal/savethemblobs.git
cp savethemblobs/savethemblobs.py /usr/local/bin/
echo "Installed Savethemblobs"

apt-get -y install gcc
cd ~ # I don't know yet why I install it
git clone https://github.com/matteyeux/iOS-Utilities.git
cd iOS-Utilities
make
make install
