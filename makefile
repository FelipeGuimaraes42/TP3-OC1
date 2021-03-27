CC=g++
CFLAGS=-Wall -Wextra -std=c++17

SOURCES := $(shell find ./src -path '*.cpp')
OBJECTS := $(patsubst ./src/%,./build/%,$(SOURCES:.cpp=.o))

./build/%.o: ./src/%.cpp ./include/%.h
	mkdir -p ./build
	$(CC) -c $(CFLAGS) -o $@ $<

./tp3: $(OBJECTS) ./main.cpp
	$(CC) $(CFLAGS) -o ./tp3 ./main.cpp $(OBJECTS)

clean:
	rm -rf ./build/*
	rm ./output/result.txt
	rm ./tp3

run:
	./tp3 ./input/input.txt