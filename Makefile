CC = gcc
uname_s = $(shell uname -s)
TARGET = decrypt0r

all : $(TARGET)

decrypt0r : src/decrypt0r.o src/firmware_tools.o
        $(CC) -o decrypt0r src/decrypt0r.o src/firmware_tools.o
        @echo "Successfully built $(TARGET) for $(uname_s)"

decrypt0r.o : src/decrypt0r.c
        $(CC) -c src/decrypt0r.c -o src/decrypt0r.o

firmware_tools.o : src/firmware_tools.c
        $(CC) -c src/firmware_tools.c -o src/firmware_tools.o

clean :
        rm -rf src/*.o decrypt0r

install :
        cp $(TARGET) /usr/local/bin/