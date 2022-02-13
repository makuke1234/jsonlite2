export CPLUS_INCLUDE_PATH=include

CXX=g++

CDEFFLAGS=-std=c++11 -Wall -Wextra -Wpedantic
CFLAGS=-O3 -Wl,--strip-all,--build-id=none,--gc-sections -fno-ident
CDFLAGS=-g -O0

TARGET=test

default: debug

debug: test.cpp
	$(CXX) $^ -o deb$(TARGET).exe $(CDEFFLAGS) $(CDFLAGS)

release: test.cpp
	$(CXX) $^ -o $(TARGET).exe $(CDEFFLAGS) $(CDLAGS)
