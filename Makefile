CC = g++
CFLAGS = -Wall -g 
OUTPATH = out
LIBS = -lSDL2 -lSDL2main


all: main app EventResolver SDLEventHandler displayConfig Renderer
	$(CC) $(CFLAGS) -o \
		$(OUTPATH)/sssnake \
		$(OUTPATH)/main.o \
		$(OUTPATH)/app.o \
		$(OUTPATH)/strings.o \
		$(OUTPATH)/EventResolver.o \
		$(OUTPATH)/SDLEventHandler.o \
		$(OUTPATH)/displayConfig.o \
		$(OUTPATH)/Renderer.o \
		$(LIBS)

main:
	$(CC) $(CFLAGS) -c main.cpp -o $(OUTPATH)/main.o $(LIBS)

app: strings
	$(CC) $(CFLAGS) -c app.cpp -o $(OUTPATH)/app.o $(LIBS)

EventResolver:
	$(CC) $(CFLAGS) -c EventResolver.cpp -o $(OUTPATH)/EventResolver.o $(LIBS)

SDLEventHandler:
	$(CC) $(CFLAGS) -c SDLEventHandler.cpp -o $(OUTPATH)/SDLEventHandler.o $(LIBS)

Renderer:
	$(CC) $(CFLAGS) -c Renderer.cpp -o $(OUTPATH)/Renderer.o $(LIBS)

strings: 
	$(CC) $(CFLAGS) -c strings.cpp -o $(OUTPATH)/strings.o $(LIBS)

displayConfig:
	$(CC) $(CFLAGS) -c displayConfig.cpp -o $(OUTPATH)/displayConfig.o $(LIBS)

clear:
	rm -rf out/*