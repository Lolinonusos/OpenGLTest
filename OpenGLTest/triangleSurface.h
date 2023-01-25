#ifndef TRIANGLESURFACE_H
#define TRIANGLESURFACE_H

#include "visObject.h"

class TriangleSurface : public visObject {
public:
	TriangleSurface();
	TriangleSurface(std::string fileName);
	~TriangleSurface();
	void readFile(std::string fileName);
	void init(int shader) override;
	void draw() override;
	//float construct();
};


#endif