#include "stdafx.h"
#include "Node.h"


Node::Node()
	: column(0)
	, line(0)
	, type(0)
	, heuristic(-1)
	, cost(0)
{
}

Node::Node(int _column, int _line, int _type)
	: column(_column)
	, line(_line)
	, type(_type)
	, heuristic(-1)
	, cost(0)
{
}

Node::~Node()
{
}
