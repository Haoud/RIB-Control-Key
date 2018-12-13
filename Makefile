CXX = g++
CXXLIBS = -lgmp -lgmpxx
CXXFLAGS = -O2 -I ./include/ -std=c++17

SRC = $(wildcard src/*.cpp)
OBJ = $(shell find ./src -type f | grep -E ".o$$")

TARGET = a.out

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(CXXLIBS) 
	
clean:
	rm -f $(OBJ) $(TARGET)
