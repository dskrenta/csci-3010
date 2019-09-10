# define vars that we will reuse
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# create target1
all: target1

# clean target1
clean:
	rm target1

# compile main.cpp and point.cpp, output it to target1
target1: Point.cpp
	$(CXX) $(CXXFLAGS) main.cpp Point.cpp -o target1