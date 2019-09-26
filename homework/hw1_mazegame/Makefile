CXX = g++
CXXFLAGS	= -std=c++11 -Wall

all: maze

clean:
	rm Player.o Maze.o Board.o maze

maze: Player.o Board.o Maze.o main.cpp
	$(CXX) $(CXXFLAGS) -o maze main.cpp Player.o Board.o Maze.o

Player.o: Player.cpp
	$(CXX) $(CXXFLAGS) -c Player.cpp

Board.o: Board.cpp
	$(CXX) $(CXXFLAGS) -c Board.cpp

Maze.o: Maze.cpp
	$(CXX) $(CXXFLAGS) -c Maze.cpp
