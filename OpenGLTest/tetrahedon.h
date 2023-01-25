#ifndef TETRAHEDON_H
#define TETRAHEDON_H

#include "visobject.h"

class Tetrahedon : public visObject {
public:
	Tetrahedon();
	~Tetrahedon();
	void init(int inMatrixUniform) override;
	void draw() override;
};

#endif