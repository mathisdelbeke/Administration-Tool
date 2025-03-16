CC = gcc
CFLAGS := -Wall -I./include

TARGET = Administration-tool

SRCS = src/main.c src/todo_sll.c src/todo_dll.c src/ring_buffer.c src/queue.c
OBJS = $(SRCS:src/%.c=build/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build $(TARGET)
	mkdir build

