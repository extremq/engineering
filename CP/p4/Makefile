CC = gcc
FLAGS = -Wall -lm

TARGET = p4
DEP = matrix.h
OBJ = matrix.o p4.o

$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(FLAGS)

%.o: %.c $(DEP)
	$(CC) -c $< -o $@ $(FLAGS)

.PHONY: clean
clean:
	rm -f *.o
	rm $(TARGET)
