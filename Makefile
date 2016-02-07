CC = gcc
OS := $(shell uname)

ifeq ($(OS),Darwin)
	# Nothing :p
else ifeq ($(OS),Linux)
	# Nothing :p
else
  $(error Unsupported operating system: $(OS))
endif

all:
		@echo 'ERROR: no platform defined.'
		@echo 'LINUX USERS: make linux'
		@echo 'MAC OS X USERS: make macos'
	 	@echo 'WINDOWS USERS: Use Decrypt0r for Windows'

linux : 
		@echo 'Building Decrypt0r for Linux...'
		@$(CC) src/decrypt0r.c src/firmware_tools.c src/firmware_tools.h -o decrypt0r
		@echo 'Succesfully built Decrypt0r for Linux'

macos : 
		@echo 'Building Decrypt0r for OS X...'
		@$(CC) src/decrypt0r.c src/firmware_tools.c src/firmware_tools.h -o decrypt0r
		@echo 'Succesfully built Decrypt0r for OS X'

iOS : 	
		@echo 'Building Decrypt0r for iOS...'
		@xcrun -sdk iphoneos clang --sysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk src/decrypt0r.c src/firmware_tools.c src/firmware_tools.h -arch armv7 -framework IOKit -framework CoreFoundation -Wall -miphoneos-version-min=6.0
		@mv a.out decrypt0r
		@echo 'Succesfully built Decrypt0r for iOS'

install : 
		@echo 'Installing Decrypt0r to your device...'
		@scp -P ${P} decrypt0r root@${IP}:/usr/local/bin/
		@echo 'Succesfully built Decrypt0r for iOS'

clean : 
		@echo "cleaning..."
		@rm -rf IPSW firmware.ipsw decrypt0r
		@echo "cleaned"
