#pragma once

#include "visObject.h"

class Point : public VisObject {
public:
	Point(float x, float y, float z, float r, float g, float b);
	~Point();
	void init(int shader) override;
	void draw() override;
};

