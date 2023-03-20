#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <stb/stb_image.h>

#include "shader.h"


class Texture {
public:

	Texture();

	Texture(const char* imageLoc, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

	Texture(const char* imageLoc, GLenum slot);

	// Assigns a texture unit to a texture
	void texUnit(Shader &shader, const char* uniform, unsigned int unit);
	void bind();
	void unbind();
	void remove();

	unsigned int ID;
private:
	GLenum type;
};

#endif