CC = gcc
uname_s = $(shell uname -s)
TARGET = decrypt0r
LDFLAGS = -lcurl -lz
OBJECTS = src/decrypt0r.o \
		  src/firmware_tools.o \
		  src/partial.o \
		  src/partialzip.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
		$(CC) -o $(TARGET) $(OBJECTS) $(LDFLAGS)
		@echo "Successfully built $(TARGET) for $(uname_s)"

$(SRC)/%.o : $(SRC)/%.c
	$(CC) -c $< -o $@

clean :
		rm -rf src/*.o decrypt0r

install : $(TARGET)
		cp $(TARGET) /usr/local/bin/
