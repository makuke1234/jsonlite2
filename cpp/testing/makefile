export CPLUS_INCLUDE_PATH=../include

CXX=g++

CDEFFLAGS=-std=c++11 -Wall -Wextra -Wpedantic
CFLAGS=-O3 -Wl,--strip-all,--build-id=none,--gc-sections -fno-ident
CDEBFLAGS=-g -O0

BIN=../../testing
TARGET=cpptest

default: debug

debug: test.cpp
	$(CXX) $^ -o $(BIN)/deb$(TARGET).exe $(CDEFFLAGS) $(CDEBFLAGS)

release: test.cpp
	$(CXX) $^ -o $(BIN)/$(TARGET).exe $(CDEFFLAGS) $(CFLAGS)

beau: beautifier.cpp
	$(CXX) $^ -o $(BIN)/cppbeautifier.exe $(CDEFFLAGS) $(CFLAGS)
