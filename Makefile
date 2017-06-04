CC = gcc
uname_s = $(shell uname -s)
TARGET = decrypt0r
CFLAGS = -I.
LDFLAGS = -lcurl -lz -lcrippy-1.0 -limg3-1.0

OBJECTS = src/decrypt0r.o \
		  src/firmware_tools.o \
		  src/partial.o \
		  src/partialzip.o \
		  src/img3crypt.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
		$(CC) $(OBJECTS) $(LDFLAGS) -o $(TARGET)
		@echo "Successfully built $(TARGET) for $(uname_s)"

$(SRC)/%.o : $(SRC)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

clean :
		rm -rf src/*.o decrypt0r

install : $(TARGET)
		cp $(TARGET) /usr/local/bin/
