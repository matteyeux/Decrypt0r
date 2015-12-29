CC = gcc
	
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
		@$(CC) src/decrypt0r.c src/firmware_tools.c src/firmware_tools.h
		@ mv a.out decrypt0r
		@echo 'Succesfully built Decrypt0r for OS X'
clean : 
		@echo "cleaning..."
		@rm -rf IPSW firmware.ipsw decrypt0r
		@echo "cleaned"
