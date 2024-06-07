# Compiler to use
CC = g++

# Compiler flags
CFLAGS = -std=c++11 -Wall

# Name of the executable
TARGET = main_HashTable

# All .cpp files in the current directory
SRCS = $(wildcard *.cpp)

# Object files for each .cpp file
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)