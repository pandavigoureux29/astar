#pragma once
class Node
{
public:
	int column;
	int line;
	int type;
	int heuristic;
	int cost;

	Node * parent;

	bool visited = false;
	int finalWayID = -1;

	Node() ;
	Node(int _i, int _j, int _type);
	~Node();

	bool Equals(Node *_n) {
		return _n->column == column && _n->line == line;
	}
};