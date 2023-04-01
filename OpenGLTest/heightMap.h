#pragma once

#include "visObject.h"

#include <stb/stb_image.h>


class HeightMap : public VisObject {
public:
	HeightMap(const char* imgPath);

	void init();
	void draw(Shader shader);

};

