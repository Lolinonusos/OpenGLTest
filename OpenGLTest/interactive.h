#pragma once

#include "visObject.h"

class Interactive : public VisObject {
public:
	Interactive();
	~Interactive();
	void init() override;
	void draw(Shader shader) override;

private:
	float movementSpeed = 2.0f; // Not in use yet
};

