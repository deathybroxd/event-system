CXX = g++
CXXFLAGS = -Wall -g -I include

# searches for every cpp
SRCS = $(wildcard src/*.cpp src/subscribers/*.cpp) main.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = event_system

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run:
	./event_system

val:
	valgrind ./event_system