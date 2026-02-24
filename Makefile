CC = gcc
CFLAGS = -Wall -Wextra
TARGET = bank
OBJS = main.o functions.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: main.c functions.h structs.h
	$(CC) $(CFLAGS) -c main.c

functions.o: functions.c functions.h structs.h
	$(CC) $(CFLAGS) -c functions.c

clean:
	rm -f $(OBJS) $(TARGET)
