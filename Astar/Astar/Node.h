#pragma once
class Node
{
public:
	int i = 0;
	int j = 0;
	int type = 0;
	int heuristic = -1;
	int cost = 0;

	bool visited = false;
	int finalWayID = -1;

	Node() ;
	Node(int _i, int _j, int _type);
	~Node();

	bool Equals(Node *_n) {
		return _n->i == i && _n->j == j;
	}
};