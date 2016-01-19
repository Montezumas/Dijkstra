graphTest: GraphTest.o Vertex.o Graph.o Maze.o Spot.o
	g++ -o graphTest GraphTest.o Vertex.o Graph.o Maze.o Spot.o
	
GraphTest.o: GraphTest.cpp 
	g++ -c GraphTest.cpp

Graph.o: Graph.cpp
	g++ -c Graph.cpp

Vertex.o: Vertex.cpp
	g++ -c Vertex.cpp	

Maze.o: Maze.cpp 
	g++ -c Maze.cpp

Spot.o: Spot.cpp
	g++ -c Spot.cpp

clean:
	rm graphTest *.o
