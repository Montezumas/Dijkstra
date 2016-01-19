#include "Graph.h"

//public
Graph::Graph(){
	gSize = gStart = gEnd = mX = mY = 0;
	vertArray = NULL;
}

Graph::~Graph(){
	if(vertArray!=NULL){
		delete []vertArray;
		vertArray=NULL;
	}
}

void Graph::init(int size){
	gSize = size;

	for(int i = 1; i <= size; i++){
		graph[i];
	}

	vertArray = new Vertex[size+1];
}

void Graph::constructMazeGraph(Maze maze){
	mX = maze.getWidth();
	mY = maze.getHeight();

	gStart = maze.startX+1 + (maze.startY * mX);
	gEnd = maze.endX+1 + (maze.endY * mX);

	int cX = 0;
	int cY = 0;

	for(int i = 1; i <= gSize; i++){

		int pX = cX - 1;
		int pY = cY - 1;

		if(maze.canMove(cY, cX, pY, cX)){
			graph[i][cX+1 + (pY * mX)] = 1;
		}
	
		if(maze.canMove(cY, cX, cY, pX)){
			graph[i][pX+1 + (cY * mX)] = 1;
		}

		int nX = cX + 1;
		int nY = cY + 1;

		if(maze.canMove(cY, cX, nY, cX)){
			graph[i][cX+1 + (nY * mX)] = 1;
		}

		if(maze.canMove(cY, cX, cY, nX)){
			graph[i][nX+1 + (cY * mX)] = 1;
		}

		if(cX < mX-1){
			cX++;
		} else{
			cX = 0;
			cY++;
		}
	}
}

void Graph::aStar(){
	for(int i = 1; i <= gSize; i ++){
		vertArray[i].num = i;
		vertArray[i].distance = numeric_limits<int>::max();
		vertArray[i].traversed = false;
		vertArray[i].previous = -1;
		pq.push(vertArray[i]);
	}

	vertArray[gEnd].distance = 0;
	pq.push(vertArray[gEnd]);

	while(!pq.empty()){
		Vertex vertNum = pq.top();
		pq.pop();
		Vertex *u = &(vertArray[vertNum.num]);

		while(u->traversed){
			Vertex vertNum = pq.top();
			pq.pop();
			Vertex *u = &(vertArray[vertNum.num]);
		}

		u->traversed = true;

		if(u->num!=gEnd){
			visitMap[u->num] = u->previous;
		}

		if(u->distance == numeric_limits<int>::max() || u->num == gStart){
			if(u->num == gStart){
				print();
			} else{
				cout << "No shortest path found" << endl;
			}
			break;
		}

		for(map<int,float>::iterator it=graph[u->num].begin(); it!=graph[u->num].end(); it++){
			int nextVertNum = it->first;
			Vertex *v = &(vertArray[nextVertNum]);	
			if(v->traversed == false){
				int h = (abs(getYFromPos(v->num)-getYFromPos(gStart)) + abs(getXFromPos(v->num)-getXFromPos(gStart)));
				if(u->distance + it->second + h < v->distance){
					v->distance = u->distance + it->second + h;
					v->previous = u->num;
					pq.push(*v);
				}
			}
		}
	}
}


void Graph::dijkstra(){
	for(int i = 1; i <= gSize; i ++){
		vertArray[i].num = i;
		vertArray[i].distance = numeric_limits<int>::max();
		vertArray[i].traversed = false;
		vertArray[i].previous = -1;
		pq.push(vertArray[i]);
	}

	vertArray[gEnd].distance = 0;
	pq.push(vertArray[gEnd]);

	while(!pq.empty()){
		Vertex vertNum = pq.top();
		pq.pop();
		Vertex *u = &(vertArray[vertNum.num]);

		u->traversed = true;

		if(u->num!=gEnd){
			visitMap[u->num] = u->previous;
		}

		if(u->distance == numeric_limits<int>::max() || u->num == gStart){
			if(u->num == gStart){
				print();
			} else{
				cout << "No shortest path found" << endl;
			}
			break;
		}

		for(map<int,float>::iterator it=graph[u->num].begin(); it!=graph[u->num].end(); it++){
			int nextVertNum = it->first;
			Vertex *v = &(vertArray[nextVertNum]);	
			if(v->traversed == false){
				if(u->distance + it->second < v->distance){
					v->distance = u->distance + it->second;
					v->previous = u->num;
					pq.push(*v);
				}
			}
		}
	}
}

//private functions
int Graph::getXFromPos(int pos){
	return ((pos-1)%(mX));
}

int Graph::getYFromPos(int pos){
	return ((pos-1)/mX);
}

void Graph::print(){
	ofstream fout;
	std::ostringstream s;
	s << "maze-" << mY << "x" << mX << "-paths.txt";
	fout.open((s.str()).c_str());

	for(map<int,int>::iterator it=visitMap.begin(); it!=visitMap.end(); it++){
		fout << getYFromPos(it->first) << " " << getXFromPos(it->first) << " " << getYFromPos(it->second) << " " << getXFromPos(it->second) << endl;
	}

  	fout.close();
}