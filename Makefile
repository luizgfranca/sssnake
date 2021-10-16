CC = g++
CFLAGS = -Wall -g 
OUTPATH = out
LIBS = -lSDL2 -lSDL2main


all: main app EventResolver SDLEventHandler
	$(CC) $(CFLAGS) -o \
		$(OUTPATH)/sssnake \
		$(OUTPATH)/main.o \
		$(OUTPATH)/app.o \
		$(OUTPATH)/strings.o \
		$(OUTPATH)/EventResolver.o \
		$(OUTPATH)/SDLEventHandler.o \
		$(LIBS)

main:
	$(CC) $(CFLAGS) -c main.cpp -o $(OUTPATH)/main.o $(LIBS)

app: strings
	$(CC) $(CFLAGS) -c app.cpp -o $(OUTPATH)/app.o $(LIBS)

EventResolver:
	$(CC) $(CFLAGS) -c EventResolver.cpp -o $(OUTPATH)/EventResolver.o $(LIBS)

SDLEventHandler:
	$(CC) $(CFLAGS) -c SDLEventHandler.cpp -o $(OUTPATH)/SDLEventHandler.o $(LIBS)

strings: 
	$(CC) $(CFLAGS) -c strings.cpp -o $(OUTPATH)/strings.o $(LIBS)

clear:
	rm -rf out/*