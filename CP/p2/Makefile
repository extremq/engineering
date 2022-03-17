CC = gcc # compiler
FLAGS = -lm -Wall # flags

TARGET = p2
DEPS = integrale.h
OBJ = p2.o integrale.o

$(TARGET): $(OBJ) $(DEPS)
	$(CC) $^ -o $@ $(FLAGS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

.PHONY: clean
clean:
	rm -f *.o
	rm $(TARGET)
