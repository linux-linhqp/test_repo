CC = g++
HEADER = -I/usr/include
LIB_DIR = /usr/local/lib
LIB = -L$(LIB_DIR) -ltag -lz

all: test

test:
	$(CC) $(CFLAGS) $(HEADER) -o test test.cpp $(LIB)

clear:
	rm -f test 
