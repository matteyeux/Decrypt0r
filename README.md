#Decrypt0r for Linux & OS X

##Big update soon 

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

#Other components

To decrypt other firmware components like kernelcache or iBoot, you have to grab the keys from theiphonewiki <br>
The first one to add is the largest, and the second one is the iv key (the smallest).<br>

### How to build it?

To build Decrypt0r just cd to the decryptr0r directory and run `make + your_os` <br> 

If you need to build XPwn for Linux, just run `build.sh`.
OS X users you have to build XPwn yourself, I'll made a bin directory with all the binaries ASAP

## TODO

- One project for OS X, GNU/Linux & Windows
- Something... :) <br>

## Credits

Thank you to my friend Elrhk ([@Dev__Jam](https://twitter.com/Dev__Jam)) for his help + tests. <br>
Developed by Mathieu Hautebas ([@matteyeux](https://twitter.com/matteyeux)) <br>
Used usefull stuff by [Lilo Colson](https://twitter.com/Pwn1d)
Thank you to [Callum Jones](https://twitter.com/icj_) for his awesome website ipsw.me.<br>

For this tool I used: <br>

- xpwn & dmg compiled from https://github.com/planetbeing/xpwn <br>
- 7zip (developed by Igor Pavlov) <br>

For more informations contact me on Twitter: [@matteyeux](https://twitter.com/matteyeux) or ask this [awesome website](http://www.google.com) (not mine). <br>
