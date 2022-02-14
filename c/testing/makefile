export C_INCLUDE_PATH=../include
export LIBRARY_PATH=../bin

CC=gcc

CDEFFLAGS=-std=c99 -Wall -Wextra -Wpedantic
CFLAGS=-O3 -Wl,--strip-all,--build-id=none,--gc-sections -fno-ident
CDEBFLAGS=-g -O0
LIB=-static -ljsonlite2

BIN=../../testing
TARGET=ctest

default: debug

debug: test.c
	$(CC) $^ -o $(BIN)/deb$(TARGET).exe $(CDEFFLAGS) $(CDEBFLAGS) $(LIB)

release: test.c
	$(CC) $^ -o $(BIN)/$(TARGET).exe $(CDEFFLAGS) $(CFLAGS) $(LIB)

beau: beautifier.c
	$(CC) $^ -o $(BIN)/cbeautifier.exe $(CDEFFLAGS) $(CFLAGS) $(LIB)
