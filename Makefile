#Makefile for Assignment 1
#Alex Zimmermann ZMMALE001


## Main Program

CC=g++
CCFLAGS=-std=c++14

SRC = src/main.cpp \
        src/main.h \
        src/StudentRecord.h \

OBJ = $(SRC:.cpp=.o)

PROG = database

$(PROG) : $(OBJ)
	$(CC) $(CCFLAGS) $(SRC) -o $(PROG)

.cpp.o:
	$(CC) $(CCFLAGS) -c $<

depend:
	$(CC) -M $(SRC) > incl.defs

clean:
	rm -f *.o
	rm -f $(PROG)
	rm -f *.pgm