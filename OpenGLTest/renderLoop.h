#pragma once

#include <vector>

class renderLoop {

	std::vector<float> objects;


	renderLoop();
	~renderLoop();

	// run initialize here
	void initialize();

	void render();
};

