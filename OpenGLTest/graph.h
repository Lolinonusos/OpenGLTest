#ifndef GRAPH_H
#define GRAPH_H

#include "visObject.h"

class Graph : public VisObject{
public:
	Graph();
	~Graph();

	void init(int inMatrixUniform) override;
	void draw() override;
};

#endif