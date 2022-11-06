# Thread Lifecycle Demo Makefile
CXX	 = g++
CXXFLAGS = -Wall -std=c++11
TARGET	 = thread_lifecycle_demo
SRC	 = thread_lifecycle_demo.cpp
LDFLAGS  = -lpthread

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(TARGET)
