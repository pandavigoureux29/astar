#include "stdafx.h"
#include "AstarExe.h"


AstarExe::AstarExe(Grid *_grid)
{
	m_grid = _grid;
}

void AstarExe::Start() {
	m_started = true;
	m_startNode = m_grid->GetStartNode();
	m_goalNode = m_grid->GetGoalNode();

	//First node to check
	m_open.push_back(m_startNode);
	
	m_debugCount = 0;

	/*while (m_open.size() > 0 && debug_count < 20) {
		
	}*/
}

void AstarExe::Update() {
	if (!m_started || m_found || m_open.size() <= 0)
		return;
	//Get best node from the OPEN list
	m_processingNode = PopBest();
	m_processingNode->visited = true;
	//keep position
	int i = m_processingNode->i, j = m_processingNode->j;

	printf("------ %d ProCESSing Node (%d,%d) -------\n",m_debugCount, i, j);

	//check if this is the goal
	if (m_processingNode->Equals(m_goalNode)) {
		printf("Found Goal\n");
		m_found = true;
		return;
	}
	else {
		CheckNeighbours(m_processingNode);
	}

	//Add current node to closed list
	m_closed.push_back(m_processingNode);
	printf("[CLOSED] Node (%d,%d) added\n", i, j);

	m_debugCount++;
}

// Checks all neighbours
void AstarExe::CheckNeighbours(Node * _node) {
	//up
	CheckNode(_node->i, _node->j - 1, _node->cost+1);
	//down
	CheckNode(_node->i, _node->j + 1, _node->cost+1);
	//left
	CheckNode(_node->i - 1, _node->j, _node->cost+1);
	//right
	CheckNode(_node->i + 1, _node->j, _node->cost+1);
}

//check a node and add it to open list if necessary
void AstarExe::CheckNode(int _i, int _j, int _cost) {
	//out of bounds
	if (_i < 0 || _i > m_grid->GetWidth() - 1 || _j < 0 || _j > m_grid->GetHeight() - 1)
		return;
	//Get Node at the position in the grid
	Node * node = &( *m_grid->GetNodeAt(_i, _j) );
	//don't process walls
	if (node->type == Grid::S_WALL_TYPE)
		return;
	//Set cost if not done yet
	if( node->cost == 0)
		node->cost = _cost;

	//Find in OPEN & CLOSE
	bool inOpen = BetterExistsInList(m_open,node);
	bool inClosed = BetterExistsInList(m_closed, node);
	//if not in any list or no better exists
	if (!inOpen && !inClosed) {
		ComputeHeuristic(node);
		printf("[OPEN] Node (%d,%d) added (h:%d)\n", _i, _j, node->heuristic);
		m_open.push_back(node);
	}
}

int AstarExe::ComputeHeuristic(Node * _node) {
	int toGoal = abs(m_goalNode->i - _node->i) + abs(m_goalNode->j - _node->j);
	//int toGoal = pow( (m_goalNode->j - _node->j), 2) + pow( (m_goalNode->i - _node->i),2);
	//toGoal = sqrt(toGoal);
	_node->heuristic =/* _node->cost*/ + toGoal;
	return _node->heuristic;
}

Node * AstarExe::PopBest() {
	int bestIndex = 0;
	int bestHeuristic = 50000;
	int bestCost = 50000;
	Node * tempNode;
	//find best heuristic index
	for (int i = 0; i < m_open.size(); i++) {
		tempNode = m_open.at(i);
		if ((tempNode->heuristic < bestHeuristic) 
			 || (tempNode->heuristic == bestHeuristic && tempNode->cost < bestCost) ) {				
			bestIndex = i;
			bestHeuristic = tempNode->heuristic;
			bestCost = tempNode->cost;
		}
	}
	//get best node
	Node * node = &(*m_open.at(bestIndex));
	//erase it from list
	m_open.erase(m_open.begin() + bestIndex);
	return node;
}

int AstarExe::FindIndexInList(std::vector<Node*> _list, Node * _toFind) {
	for (int i = 0; i < _list.size(); i++) {
		if (_toFind->Equals(_list.at(i)) ) {
			return i;
		}
	}
	return -1;
}

bool AstarExe::BetterExistsInList(std::vector<Node*> _list, Node * _toFind) {
	for (int i = 0; i < _list.size(); i++) {
		if (_toFind->Equals(_list.at(i)) ) {
			if( _list.at(i)->cost <= _toFind->cost)
				return true;
		}
	}
	return false;
}

AstarExe::~AstarExe()
{
}
