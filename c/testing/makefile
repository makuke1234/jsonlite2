export C_INCLUDE_PATH=../include
export LIBRARY_PATH=../bin

CC=gcc

CDEFFLAGS=-std=c99 -Wall -Wextra -Wpedantic
CFLAGS=-O3 -Wl,--strip-all,--build-id=none,--gc-sections -fno-ident
CDEBFLAGS=-g -O0
LIB=-static -ljsonlite2

TARGET=test

default: debug

debug: test.c
	$(CC) $^ -o deb$(TARGET).exe $(CDEFFLAGS) $(CDEBFLAGS) $(LIB)

release: test.c
	$(CC) $^ -o $(TARGET).exe $(CDEFFLAGS) $(CFLAGS) $(LIB)

beau: beautifier.c
	$(CC) $^ -o beautifier.exe $(CDEFFLAGS) $(CFLAGS) $(LIB)
