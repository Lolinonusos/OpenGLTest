#ifndef XYZ_H
#define XYZ_H

#include "visObject.h"

class XYZ : public visObject {
public:
	XYZ();
	~XYZ();
	void init(int inMatrixUniform) override;
	void draw() override;
};

#endif