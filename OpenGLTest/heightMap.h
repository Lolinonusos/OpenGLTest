#pragma once

#include "visObject.h"

#include <stb/stb_image.h>


class HeightMap : public VisObject {
public:
	HeightMap(const char* imgPath, Shader* inShader, std::string inName);

	void FromImageFile(const std::string& fileName, float size, float maxHeight, unsigned resolution);

	void init();
	void draw();


	float getTerrainHeight(const glm::vec2& position);
	static glm::vec3 getBarycCoordinate(const glm::vec2& A, const glm::vec2& B, const glm::vec2& C, const glm::vec2& point);

private:
	unsigned int NUM_STRIPS;
	unsigned int NUM_VERTS_PER_STRIP;

};