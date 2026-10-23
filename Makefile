CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -fstack-protector -Iinclude
TARGET = projet_svg


SRC = $(wildcard src/*.c) 

build:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) 

run:
	./$(TARGET)
clean:
	rm -f $(TARGET)