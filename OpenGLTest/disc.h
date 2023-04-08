#pragma once

#include "visObject.h"

class Disc : public VisObject {
public:
	Disc(Shader *inShader);
	~Disc();
	void init() override;
	void draw() override;

	void construct();

protected:
	float radius{ 0.5 };
	
};

