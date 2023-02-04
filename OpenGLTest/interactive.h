#pragma once

#include "visObject.h"

class Interactive : public visObject {
	Interactive();
	~Interactive();
	void init(int shader) override;
	void draw() override;

	void move();
};

