#ifndef VERTEX_H
#define VERTEX_H

class Vertex{
	private:
	public:
		int num, distance, previous;
		bool traversed;
		Vertex();
		~Vertex();
		bool operator()(const Vertex& a, const Vertex& b) const;
};

#endif