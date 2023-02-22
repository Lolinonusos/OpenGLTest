#pragma once

#include "visObject.h"

class Point : public visObject {
public:
	Point(int pointSize, float x, float y, float z, float r, float g, float b);
	~Point();
	void init(int shader) override;
	void draw() override;
};

