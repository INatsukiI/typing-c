CC     = gcc
RM     = rm -rf
CFLAGS = -c -Wall
OBJ    = typing.o size.o screen.o game.o 
PRG    = typing

$(PRG): $(OBJ)
	$(CC) -o $(PRG) $(OBJ) -lncursesw
typing.o: typing.c
	$(CC) $(CFLAGS) typing.c
size.o: size.c size.h
	$(CC) $(CFLAGS) size.c
screen.o: screen.c screen.h
	$(CC) $(CFLAGS) screen.c
game.o: game.c game.h game_key_define.h
	$(CC) $(CFLAGS) game.c

clean:
	$(RM) $(PRG) $(OBJ)
