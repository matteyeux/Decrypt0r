#!/bin/bash
#Script written by matteyeux
#RUN THIS SCRIPT AS ROOT
#Just to help people

echo 'You need to run this script as root'

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

cd ~
git clone https://github.com/xerub/xpwn.git
mkdir ~/build
cd ~/build 
cmake ~/xpwn
make
make package
tar xvjf XPwn-0.5.8-Linux.tar.bz2

echo "Check the XPwn-0.5.8-Linux folder"