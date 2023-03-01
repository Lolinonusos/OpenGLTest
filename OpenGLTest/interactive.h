#pragma once

#include "visObject.h"

class Interactive : public VisObject {
public:
	Interactive();
	~Interactive();
	void init(int shader) override;
	void draw() override;

	//void move(float inX, float inY, float inZ, float deltaTime);
private:
	float movementSpeed = 2.0f; // Not in use yet
};

