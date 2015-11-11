#pragma once

#include "Grid.h"

class AstarExe
{

	struct Node {
	public :
		int i = 0;
		int j = 0;
		int type = 0;
		int heuristic = -1;
		int cost = 0;
	public:
		Node() {};
		Node(int _i, int _j, int _type) {
			i = _i;
			j = _j;
			_type = _type;
		}

		bool Equals(Node *_n) {
			return _n->i == i && _n->j == j;
		}
	};

private :
	Grid * m_grid;
	std::vector<Node*> m_open;
	std::vector<Node*> m_closed;
	Node m_goal;

	int ComputeHeuristic(Node * _node,Node * _goal);
	void CheckNeighbours(int i, int j,int _cost);
	void CheckNode(int i, int j, int _cost);

	Node * PopBest();
	int FindIndexInList(std::vector<Node*> _list, Node * _toFind);
	bool BetterExistsInList(std::vector<Node*> _list, Node * _toFind);

public:
	AstarExe(Grid *_grid);
	~AstarExe();

	void Start();
};

