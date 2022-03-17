CC = gcc # compiler
FLAGS = -Wall # flags

TARGET = exec
DEPS = integrale.h
OBJ = exec.o integrale.o

$(TARGET): $(OBJ)
	$(CC) $(FLAGS) $^ -o $(TARGET)

%.o: %.c $(DEPS)
	$(CC) $(FLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f *.o
	rm $(TARGET)