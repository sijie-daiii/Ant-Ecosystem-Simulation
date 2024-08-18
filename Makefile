CXX = g++
CXXFLAGS = -Iinclude -g -O0 -std=c++11

SRC_DIR = src
INCLUDE_DIR = include

SRCS = $(wildcard $(SRC_DIR)/*.cpp) main.cpp

OBJS = $(patsubst %.cpp, %.o, $(SRCS))

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(SRC_DIR)/*.o
	rm -f *.o
	rm -f $(TARGET)
	rm -f *~ core $(INCLUDE_DIR)/*~

.PHONY: clean all
