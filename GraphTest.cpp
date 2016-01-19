#include "Graph.h"
#include <iostream>

using namespace std;
int main(int argc,char *argv[]){
	
	while ((argc<3) || (argc>4))	
	{
		cout << "Run the program as ./graphTest -m maze-file.txt (-Astar)" << endl;
		return 1;
	}

	Maze maze;
	Graph graph;
	bool aStar = false;

 	int i = 1;

	while (i<argc)
	{
		if (strcmp(argv[i],"-m")==0){
			if ((i+1)>=argc){
				cout << "Run the program as ./graphTest -m maze-file.txt (-Astar)" << endl;
				return 2;
			}

			if(!maze.readMaze(argv[i+1])){
				cout << "File does not exist" << endl;
				return 3;
			}

			graph.init(maze.getHeight() * maze.getWidth());
			graph.constructMazeGraph(maze);
		}

		if(strcmp(argv[i],"-Astar")==0){
			aStar= true;
		}

		i++;
	}

	if(aStar){
		graph.aStar();
	} else{
		graph.dijkstra();
	}

	return 0;
}