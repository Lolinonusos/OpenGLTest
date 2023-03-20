#ifndef TETRAHEDON_H
#define TETRAHEDON_H

#include "visobject.h"

class Tetrahedon : public VisObject {
public:
	Tetrahedon();
	~Tetrahedon();
	void init() override;
	void draw(Shader shader) override;
};

#endif