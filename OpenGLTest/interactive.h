#pragma once

#include "visObject.h"

class Interactive : public VisObject {
public:
	Interactive(Shader *inShader);
	~Interactive();
	void init() override;
	void draw() override;

private:
	float movementSpeed = 2.0f; // Not in use yet
};

