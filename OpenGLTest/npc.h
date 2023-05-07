#pragma once

#include "triangleSurface.h"
#include "graph.h"
#include "octahedronBall.h"

class npc : public OctahedronBall{
public:
    npc (Shader* inShader, std::string inName) {
		model = glm::mat4(1.0f);
		objShader = inShader;
		name = inName;


	};

    int NodeIndex = 0;

    int VertAmount = 0;

    bool GoingBack;

    std::vector<glm::vec3> vPositions;

    void getGraphPositions(TriangleSurface grap) {
        for (int i = 0; i < grap.vertexAmount(); i++) {
            vPositions.push_back(grap.getVertexPosition(i));
        }
    }

	void FollowCurve(TriangleSurface grap, float deltaTime) {

        glm::vec3 trans;

        if (NodeIndex < VertAmount && GoingBack) {
            glm::vec3 temp = vPositions[NodeIndex];

            trans = temp - position;

            translate(trans[0], trans[1], trans[2], deltaTime);

            if (position == vPositions[NodeIndex]) {
                NodeIndex++;
            }
            if (NodeIndex >= VertAmount - 1) {
                GoingBack = false;
            }
        }
        else if (NodeIndex >= 0 && !GoingBack) {
            glm::vec3 temp = vPositions[NodeIndex];

            trans = temp - position;

            translate(trans[0], trans[1], trans[2], deltaTime);

            if (position == vPositions[NodeIndex]); {
                NodeIndex--;
            }
            if (NodeIndex <= 0) {
                NodeIndex = 0;
                GoingBack = true;
            }
        }
    }
};

