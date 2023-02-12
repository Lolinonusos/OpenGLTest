#pragma once

#include "visObject.h"

class Disc : public visObject {
public:
	Disc();
	~Disc();
	void init(int shader) override;
	void draw() override;

	void construct();

protected:
	float radius{ 0.5 };
	
};

