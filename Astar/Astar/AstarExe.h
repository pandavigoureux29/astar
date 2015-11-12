#pragma once

#include "Grid.h"
#include "Node.h"

class AstarExe
{

private :
	Grid * m_grid;
	std::vector<Node*> m_open;
	std::vector<Node*> m_closed;
	Node * m_startNode;
	Node * m_goalNode;

	//Runtime variables
	bool m_started = false;
	bool m_found = false;
	int m_debugCount = 0;
	Node * m_processingNode;

	int ComputeHeuristic(Node * _node);
	void CheckNeighbours(Node * _node);
	void CheckNode(int i, int j, int _cost);

	Node * PopBest();
	int FindIndexInList(std::vector<Node*> _list, Node * _toFind);
	bool BetterExistsInList(std::vector<Node*> _list, Node * _toFind);

public:
	AstarExe(Grid *_grid);
	~AstarExe();

	void Start();
	void Update();
};

