export C_INCLUDE_PATH=include

BIN=bin
OBJ=obj
SRC=src
TARGET=jsonlite2

CC=gcc
CDEFFLAGS=-std=c99 -Wall -Wextra -Wpedantic -Wconversion
CFLAGS=-O3 -Wl,--strip-all,--build-id=none,--gc-sections -fno-ident -D NDEBUG
CDEFFLAGS=-g -O0 -D _DEBUG

SRCFILES=$(wildcard $(SRC)/*.c)

RELOBJFILES=$(SRCFILES:%.c=%.c.o)
RELOBJFILES:=$(RELOBJFILES:$(SRC)/%=$(OBJ)/%)

DEBOBJFILES=$(SRCFILES:%.c=%.c.d.o)
DEBOBJFILES:=$(DEBOBJFILES:$(SRC)/%=$(OBJ)/%)

default: release

rel: release
deb: debug


release: $(RELOBJFILES)
	ar rcs $(BIN)/lib$(TARGET).a $^
	strip $(BIN)/lib$(TARGET).a
	$(CC) $^ -shared -o $(BIN)/$(TARGET).dll $(CFLAGS) -Wl,--out-implib=$(BIN)/lib$(TARGET).dll.a
	strip $(BIN)/lib$(TARGET).dll.a

debug: $(DEBOBJFILES)
	ar rcs $(BIN)/libdeb$(TARGET).a $^
	$(CC) $^ -shared -o $(BIN)/deb$(TARGET).dll -Wl,--out-implib=$(BIN)/libdeb$(TARGET).dll.a


$(OBJ)/%.c.o: $(SRC)/%.c $(OBJ) $(BIN)
	$(CC) -c $< -o $@ $(CDEFFLAGS) $(CFLAGS)
$(OBJ)/%.c.d.o: $(SRC)/%.c $(OBJ) $(BIN)
	$(CC) -c $< -o $@ $(CDEFFLAGS) $(CDEFFLAGS)

$(OBJ):
	mkdir $(OBJ)

$(BIN):
	mkdir: $(BIN)

clean:
	rm -r -f $(OBJ)
	rm -f $(BIN)/*.a
