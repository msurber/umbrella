#DEBUG  = -g -O0
DEBUG   = -O3
CC      = gcc
INCLUDE = -I/usr/local/include
CFLAGS  = $(DEBUG) -Wall $(INCLUDE) -Winline -pipe

LDFLAGS = -L/usr/local/lib
LDLIBS    = -lwiringPi -lwiringPiDev -lpthread -lm -lcolourOled

SRC = umbrella.cpp

OBJ     =       $(SRC:.c=.o)

BINS    =       $(SRC:.c=)

umbrella: umbrella.o
        @echo [link]
        @$(CC) -o $@ umbrella.o  $(LDFLAGS) $(LDLIBS)
