CC = gcc
TARGET = test
SRC = $(wildcard ./*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

CFLAGES = -c -Wall

$(TARGET):$(OBJ)
	$(CC) -o $@ $(OBJ) -lpthread
%.o: %.c
	$(CC) $(CFLAGES) $< -o $@

.PHONY:clean
clean:
	rm -f *.o $(TARGET)