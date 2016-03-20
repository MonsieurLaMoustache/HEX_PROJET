CC=gcc
SDL= `sdl-config --cflags --libs` -lSDL -lSDL_ttf -lSDL_image -lm
EXE=hex_v1.exe

all: $(EXE)

$(EXE): Formes.o main.o
	gcc -o $(EXE) Formes.o main.o $(SDL)

Formes.o: Formes.c
	gcc -o Formes.o -c Formes.c

main.o: main.c Formes.h
	gcc -o main.o -c main.c

clean:
	rm -rf *.o
