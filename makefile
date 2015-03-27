CC=gcc
CFLAGS=-c -march=native -O2 -Wall
MATH=-lm
SOURCES=ermac.c main.c
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=build.exe
DEPS=ermac.h

all: $(SOURCES) $(EXECUTABLE)

build.exe: ermac.c main.c
	$(CC) -o build.exe ermac.c main.c $(MATH)

ermac.o: ermac.c
	$(CC) $(CFLAGS) ermac.c $(MATH)

main.o: main.c
	$(CC) $(CFLAGS) main.c 

clean: 
	rm *o hello
