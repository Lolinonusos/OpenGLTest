#ifndef GRAPH_H
#define GRAPH_H

#include "visObject.h"

class Graph : public VisObject{
public:
	Graph(Shader *inShader);
	~Graph();

	void init() override;
	void draw() override;
};

#endif