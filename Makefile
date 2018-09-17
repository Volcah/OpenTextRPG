SOURCE=Source/Main.cpp Source/Enemy.cpp Source/Engine.cpp Source/Location.cpp Source/Player.cpp
OUTPUT=Main.o Enemy.o Engine.o Location.o Player.o

CFLAGS=-g -std=c++11
LIBS=-lm
CC=g++

PROGRAM_NAME=OTRPG

linux:
	$(CC) $(CFLAGS) $(SOURCE) -o $(PROGRAM_NAME)

switch:
	make -f Makefile.nx
