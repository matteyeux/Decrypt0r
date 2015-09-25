CC = gcc

all : 
	@echo 'Building Decrypt0r for Linux'
	@$(CC) src/decrypt0r.c src/firmware_tools.c src/firmware_tools.h -o decrypt0r
	@echo 'Succesfully built Decrypt0r for Linux'