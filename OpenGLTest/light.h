#pragma once
#include "visObject.h"

class Light : public VisObject {
public:
	Light(Shader *inShader, std::string inName);

	void init();

	void draw();



	float ambientStrength{ 0.3f };
	glm::vec3 ambientColour{ 0.3f, 0.3f, 0.3f };
	
	float lightStrength{ 0.7f };
	glm::vec3 lightColour{ 1.0f, 0.0f, 0.0f };

	float specularStrength{ 0.9f };
	int specularExponent{ 4 };
};

