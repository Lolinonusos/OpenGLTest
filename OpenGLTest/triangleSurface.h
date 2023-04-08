#ifndef TRIANGLESURFACE_H
#define TRIANGLESURFACE_H

#include "visObject.h"

class TriangleSurface : public VisObject {
public:
	TriangleSurface(Shader *inShader);
	TriangleSurface(std::string fileName, bool write);
	~TriangleSurface();
	void writefile(std::string fileName);
	void readFile(std::string fileName);
	void init() override;
	void draw() override;
	//float construct();
};


#endif