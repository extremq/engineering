CC = gcc
FLAGS = -Wall

TARGET = main
DEPS = date.h
OBJ = main.o date.o

$(TARGET): $(OBJ) $(DEPS)
	$(CC) $^ -o $@ $(FLAGS)

%.o: %.c $(DEPS)
	$(CC) -c $< -o $@ $(FLAGS)

.PHONY: clean
clean:
	rm -f *.o
	rm $(TARGET)
