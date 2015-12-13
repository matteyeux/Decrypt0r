#Decrypt0r

###Rootfs decrypting

To decrypt rootfs or other components like IMG3 files you have to grab keys from [iPhonewiki](https://www.theiphonewiki.com/wiki/Firmware_Keys). <br>

First download the IPSW you choose to decrypt, you can download it directly with my tool or from ipsw.me. <br>
The program will ask you to add the keys grabed from iphonewiki (only one for the rootfs). <br>

Specify the name of the file containing rootfs (ex 058-24465-023.dmg). <br>
In the IPSW file, there is three dmg files, rootfs is the biggest. <br>

Then the program is going to work automaticaly. <br>

If you want to modify rootfs (ex Setup.app) you can use TransMac for Windows. But it won't work to bypass iCloud <br>

### Encryption of rootfs and creating a Custom fimware

You can create a Custom fimware but it's crap. Be patient. <br>
Downgrades are already impossible without SHSHs blobs, on devices that do not have low level exploits (RIP Limera1n). <br>
Is this feature useless ? <br>
Yes, but it can still be used. <br>

###IMG3

To decrypt IMG3 files like kernelcache or iBoot, you have to grab the keys from theiphonewiki <br>
The first one to add is the largest, and the second one is the iv key (the smallest).<br>
Then follow instructions.<br>

###How to build it?

To build Decrypt0r just cd to the decryptr0r directory and run `make + your_os` <br> 

If you need to build XPwn for Linux, just run `build.sh`.
OS X users you have to build XPwn yourself, I'll made a bin directory with all the binaries ASAP

###Compatibility

Decrypt0r is compatible with Linux & OS X, Windows users, check [Decrypt0r for Windows](https://github.com/matteyeux/Decrypt0r-for-Windows)<br>

###Binaries
For people who doesn't want to run my script or are running OS X you have the possibility to download this file which contains OS X & Linux64 binaries<br>
Download [here](https://www.dropbox.com/s/r6e5fwae2ff7ecv/XPwn%20binaries.zip?dl=0)

## Credits

Thank you to : 
My friend [@Dev__Jam](https://twitter.com/Dev__Jam) for his help + tests. <br>
The usefull stuff by [Lilo Colson](https://twitter.com/Pwn1d)
Reimagine tool made by [Danzatt](https://twitter.com/danzatt)
[Callum Jones](https://twitter.com/icj_) for his awesome website ipsw.me.<br>
[iNeal](https://twitter.com/iNeal) for savethemblobs
Developed by Mathieu Hautebas ([@matteyeux](https://twitter.com/matteyeux)) <br>

For this tool I used: <br>

- xpwn & dmg compiled from https://github.com/xerub/xpwn <br>
- 7zip (developed by Igor Pavlov) <br>
- Reimagine
- Savethemblobs

For more informations contact me on Twitter: [@matteyeux](https://twitter.com/matteyeux) or ask this [awesome website](http://www.google.com) (not mine). <br>
