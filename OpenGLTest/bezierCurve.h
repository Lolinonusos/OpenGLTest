#pragma once

#include "visObject.h"

class BezierCurve : public VisObject {
	BezierCurve(Shader inShader);

	void init() override;
	void draw() override;
};

