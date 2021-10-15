CC = g++
CFLAGS = -Wall -g 
LIBS = -lSDL2 -lSDL2main

all: main app
	$(CC) $(CFLAGS) -o sssnake main.o app.o strings.o $(LIBS)

main:
	$(CC) $(CFLAGS) -c main.cpp $(LIBS)

app: strings
	$(CC) $(CFLAGS) -c app.cpp $(LIBS)

strings: 
	$(CC) $(CFLAGS) -c strings.cpp $(LIBS)