#include "Vertex.h"

Vertex::Vertex(){
	num = 0;
	distance = 0;
	previous = -1;
	traversed = false;
}

Vertex::~Vertex(){

}

//return greater to have min heap property in priority queue
bool Vertex::operator()(const Vertex& a, const Vertex& b) const{
	return (a.distance>b.distance);
}