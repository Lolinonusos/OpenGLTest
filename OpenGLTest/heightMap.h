#pragma once

#include "visObject.h"

#include <stb/stb_image.h>


class HeightMap : public VisObject {
public:
	HeightMap(const char* imgPath, Shader* inShader, std::string inName);

	void init();
	void draw();

private:
	unsigned int NUM_STRIPS;
	unsigned int NUM_VERTS_PER_STRIP;

};