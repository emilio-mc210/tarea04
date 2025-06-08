CC = gcc
CFLAGS = -Wall
BUILD = build/
OUT = build/main

all: $(OUT)

$(OUT): build/main.o build/stack.o build/linked_list.o
	$(CC) $(CFLAGS) -o $@ $^

build/main.o: src/main.c $(BUILD)
	$(CC) $(CFLAGS) -c -o $@ $<

build/stack.o: src/stack.c $(BUILD)
	$(CC) $(CFLAGS) -c -o $@ $<

build/linked_list.o: src/linked_list.c $(BUILD)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD):
	mkdir build

clean: $(BUILD)
	rm -r $<