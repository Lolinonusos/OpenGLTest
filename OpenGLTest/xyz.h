#ifndef XYZ_H
#define XYZ_H

#include "visObject.h"

class XYZ : public VisObject {
public:
	XYZ();
	~XYZ();
	void init(int inMmatrixUniform) override;
	void draw(Shader shader) override;
};

#endif