#pragma once

#include "visObject.h"

class Disc : public VisObject {
public:
	Disc();
	~Disc();
	void init() override;
	void draw(Shader shader) override;

	void construct();

protected:
	float radius{ 0.5 };
	
};

