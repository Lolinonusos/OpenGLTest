#pragma once

#include "visObject.h"

class BezierCurve : public VisObject {
	BezierCurve();

	void init(int shader) override;
	void draw(Shader shader) override;
};

