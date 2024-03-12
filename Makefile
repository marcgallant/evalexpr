# Simple Makefile

# Compilers vars
CC=gcc
CFLAGS=-std=c99 -pedantic -Werror -Wall -Wextra -Wvla -Isrc
LDFLAGS=-g -fsanitize=address

SRC= \
     src/token/oper/oper.c \
     src/token/token.c \
     src/queue/queue.c \
     src/stack/stack.c \
     src/evalexpr.c \
     src/main.c \

OBJ= $(SRC:.c=.o)

.PHONY: all clean

all: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o evalexpr $(OBJ)

check: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o evalexpr $(OBJ)
	cd tests && ./basics.sh

clean:
	$(RM) $(OBJ) evalexpr

# END Makefile
