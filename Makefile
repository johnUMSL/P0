# Makefile for P0 project
# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

TARGET = P0
SOURCES = P0.cpp tree.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)
	rm -f *.o
	rm -f *.*order