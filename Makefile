CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Iinclude
TARGET = projet_svg


SRC = $(wildcard src/*.c) #On cherche tous les fichiers .c automatiquement pour eviter de devoir tous les taper manuellement dans le build

#On construit le build grace aux fichiers recupérés par la fonction wildcard
build:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) 

clean:
	rm -f $(TARGET)