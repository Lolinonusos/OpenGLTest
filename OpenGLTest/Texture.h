#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <stb/stb_image.h>

#include "shader.h"


class Texture{
public:
	Texture(const char* imageLoc, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

	// Assigns a texture unit to a texture
	void texUnit(Shader &shader, const char* uniform, unsigned int unit);
	void bind();
	void unbind();
	void remove();

private:
	unsigned int ID;
	GLenum type;
};

#endif