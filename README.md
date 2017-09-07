# Decrypt0r

```
 ____                             _    ___
|  _ \  ___  ___ _ __ _   _ _ __ | |_ / _ \ _ __
| | | |/ _ \/ __| '__| | | | '_ \| __| | | | '__|
| |_| |  __/ (__| |  | |_| | |_) | |_| |_| | |
|____/ \___|\___|_|   \__, | .__/ \__|\___/|_|
 Version 1.2.0        |___/|_| by matteyeux

```

### Rootfs decrypting

To decrypt rootfs or other components like IMG3 files you have to grab keys from [iPhonewiki](https://www.theiphonewiki.com/wiki/Firmware_Keys). <br>

First download the IPSW you want to decrypt, you can download it directly with my tool or from ipsw.me. <br>
The program will ask you to add the keys grabed from iphonewiki (only one for the rootfs). <br>

Specify the name of the file containing rootfs (ex 058-24465-023.dmg). <br>
In the IPSW file, there is three dmg files, rootfs is the biggest. <br>

Then the program is going to work automaticaly. <br>

If you want to modify rootfs (ex Setup.app) you can use TransMac for Windows, whatever it won't <br>

### Encrypting rootfs and creating a Custom fimware

You can create a Custom fimware. You won't be able to restore whith it. <br>
Is this feature useless ? <br>
Yes, but it can still be used. <br>

### IMG3

To decrypt IMG3 files like kernelcache or iBoot, you have to grab the keys from theiphonewiki <br>
The first one to add is the largest, and the second one is the iv key (the smallest).<br>
Then follow instructions.<br>

### IMG4 

Decrypt0r now supports IMG4 (or im4P, whatever) files. I added a function which checks if the file is an IM4P or not.

You can also decompress compressed iPhone 7 kernelcache when it asks for firmware just press `[enter]`.

### How to build it?

To build Decrypt0r just cd to the decryptr0r directory and run `make` <br> 

To build Xpwn and other stuff run `build.sh` on Debian like distros. <br>
macOS users can download bins [here](https://www.dropbox.com/s/r6e5fwae2ff7ecv/XPwn%20binaries.zip?dl=0)

### Compatibility

Decrypt0r is compatible with Linux & macOS. <br>
Windows users, check [Decrypt0r for Windows](https://github.com/matteyeux/Decrypt0r-for-Windows)<br>


## Credits

Credits go to :  
My friend [@Dev__Jam](https://twitter.com/Dev__Jam) for initial idea and some code. <br>
Some functions by  [Lilo Colson](https://twitter.com/Pwn1d) <br>
Reimagine tool made by [Danzatt](https://twitter.com/danzatt) <br>
[Callum Jones](https://twitter.com/icj_) for his awesome website ipsw.me & API .<br>
Joshua Hill for libimg3

Developed by Mathieu Hautebas ([@matteyeux](https://twitter.com/matteyeux)) <br>

For this tool I used: <br>

- XPwn compiled from https://github.com/xerub/xpwn <br>
- 7zip (developed by Igor Pavlov) <br>
- Reimagine
- [img4tool](https://github.com/xerub/img4tool)

For more informations contact me on Twitter: [@matteyeux](https://twitter.com/matteyeux) or ask this [awesome website](http://www.google.com) (not mine). <br>

Feel free to contribute
