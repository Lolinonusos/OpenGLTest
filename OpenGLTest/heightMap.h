#pragma once

#include "visObject.h"

#include <stb/stb_image.h>


class HeightMap : public VisObject {
public:
	HeightMap(const char* imgPath, Shader* inShader, std::string inName);

	void FromImageFile(const std::string& fileName, float size, float maxHeight, unsigned resolution);

	void init();
	void draw();

	void bary(glm::vec3 point);

private:
	unsigned int NUM_STRIPS;
	unsigned int NUM_VERTS_PER_STRIP;

};