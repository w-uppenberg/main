# Standard Makefile

CXX = g++
CXXFlags = -std=c++11 -Wall -O2

TARGET = main
OBJS = main.o an_object.o

all:	$(TARGET)
	./$(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS)
