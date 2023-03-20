#pragma once

#include "visObject.h"

class BezierCurve : public VisObject {
	BezierCurve();

	void init() override;
	void draw(Shader shader) override;
};

