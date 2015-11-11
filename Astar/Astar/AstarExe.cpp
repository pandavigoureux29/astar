#include "stdafx.h"
#include "AstarExe.h"


AstarExe::AstarExe(Grid *_grid)
{
	m_grid = _grid;
}

void AstarExe::Start() {
	//build Start node
	int * stPoint = m_grid->GetStartPoint();
	Node start(stPoint[0], stPoint[1], Grid::S_START_TYPE);
	//build goal node
	int * goalPoint = m_grid->GetGoalPoint();
	m_goal = Node(goalPoint[0], goalPoint[1], Grid::S_GOAL_TYPE);

	//First node to check
	m_open.push_back(&start);

	//position
	int i = start.i, j = start.j;

	int debug_count = 0;

	while (m_open.size() > 0 && debug_count < 20) {
		Node * currentNode = PopBest();
		i = currentNode->i; j = currentNode->j;

		printf("------LOOP (%d,%d) -------\n", i,j);
		
		//check if this is the goal
		if (currentNode->Equals(&m_goal)) {
			printf("Found Goal\n");
			return;
		}
		else {
			CheckNeighbours(i, j, currentNode->cost +1);
		}

		//Add current node to closed list
		m_closed.push_back(currentNode);
		printf("[CLOSED] Node (%d,%d) added\n", i, j);

		debug_count++;
	}
}

// Checks all neighbours
void AstarExe::CheckNeighbours(int _i, int _j, int _cost) {
	//up
	CheckNode(_i, _j - 1, _cost);
	//down
	CheckNode(_i, _j + 1, _cost);
	//left
	CheckNode(_i - 1, _j, _cost);
	//right
	CheckNode(_i + 1, _j, _cost);
}

//check a node and add it to open list if necessary
void AstarExe::CheckNode(int _i, int _j, int _cost) {
	//out of bounds
	if (_i < 0 || _i > m_grid->GetWidth() - 1 || _j < 0 || _j > m_grid->GetHeight() - 1)
		return;
	//type of the processed cell
	int type = m_grid->GetValueAt(_i, _j);
	//don't process walls
	if (type == Grid::S_WALL_TYPE)
		return;
	
	//Create node
	Node * node = new Node(_i, _j, type);
	if( node->cost == 0)
		node->cost = _cost;

	//Find in OPEN & CLOSE
	bool inOpen = BetterExistsInList(m_open,node);
	bool inClosed = BetterExistsInList(m_closed, node);
	//if not in any list
	if (!inOpen && !inClosed) {
		ComputeHeuristic(node, &m_goal);
		printf("[OPEN] Node (%d,%d) added (h:%d)\n", _i, _j, node->heuristic);
		m_open.push_back(node);
	}
}

int AstarExe::ComputeHeuristic(Node * _node,Node * _goal) {
	int toGoal = abs(_goal->i - _node->i) + abs(_goal->j - _node->j);
	_node->heuristic = _node->cost + toGoal;
	return _node->heuristic;
}

AstarExe::Node * AstarExe::PopBest() {
	int bestIndex = 0;
	int bestHeuristic = 50000;
	//find best heuristic index
	for (int i = 0; i < m_open.size(); i++) {
		if (m_open.at(i)->heuristic <= bestHeuristic) {
			bestIndex = i;
			bestHeuristic = m_open.at(i)->heuristic;
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
