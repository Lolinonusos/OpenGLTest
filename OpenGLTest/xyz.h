#ifndef XYZ_H
#define XYZ_H

#include "visObject.h"

class XYZ : public VisObject {
public:
	XYZ(Shader *shader);
	~XYZ();
	void init() override;
	void draw() override;
};

#endif