#ifndef TRIANGLESURFACE_H
#define TRIANGLESURFACE_H

#include "visObject.h"

class TriangleSurface : public VisObject {
public:
	TriangleSurface();
	TriangleSurface(std::string fileName, bool write);
	~TriangleSurface();
	void writefile(std::string fileName);
	void readFile(std::string fileName);
	void init() override;
	void draw(Shader shader) override;
	//float construct();
};


#endif