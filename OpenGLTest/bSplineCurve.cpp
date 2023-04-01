#include "bSplineCurve.h"

bSplineCurve::bSplineCurve() {
    for (auto x = t[grad]; x < sizeof(t); x += 0.05f) {
        auto p = deBour(x);
        vertices.push_back(p);
    }

}

glm::vec3 bSplineCurve::deBour(float t)
{

    return glm::vec3();
}
