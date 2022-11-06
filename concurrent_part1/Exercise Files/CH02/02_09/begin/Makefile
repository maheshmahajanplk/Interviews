# Detached Thread Demo Makefile
CXX	 = g++
CXXFLAGS = -Wall -std=c++11
TARGET	 = detached_thread_demo
SRC	 = detached_thread_demo.cpp
LDFLAGS  = -lpthread

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(TARGET)
