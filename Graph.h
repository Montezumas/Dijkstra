#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <queue>
#include <sstream>
#include <iostream>
#include "Maze.h"
#include "Vertex.h"

using namespace std;
class Graph{
	private:
		//graph properties
		int gSize, gStart, gEnd, mX, mY;
		//vertex adjacencies
		map<int, map<int, float> > graph;
		//array of vertex properties
		Vertex *vertArray;
		//for queueing the verticies when finding path
		priority_queue<Vertex, vector<Vertex>, Vertex> pq;
		//each pair represents {visited vertex, next vertex on shortest path to gEnd}
		map<int, int> visitMap;
		//print to maze-XxY-paths.txt
		void print();
		//convert an int into x or y coordinate
		int getXFromPos(int pos);
		int getYFromPos(int pos);
	public:
		Graph();
		~Graph();
		void init(int size);
		void constructMazeGraph(Maze maze);
		void dijkstra();
		void aStar();
};

#endif