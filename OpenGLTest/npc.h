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

    float seconds{};

    void getGraphPositions(TriangleSurface* grap) {
        for (int i = 0; i < grap->vertexAmount(); i++) {
            vPositions.push_back(grap->getVertexPosition(i));
        }
        VertAmount = grap->vertexAmount();
    }

	void FollowCurve(TriangleSurface* grap, float deltaTime) {
        seconds += deltaTime;
        //if (true) {
        if (seconds > 0.01f) {
        
            glm::vec3 trans;

            if (NodeIndex < VertAmount && GoingBack) {
                glm::vec3 temp = grap->getVertexPosition(NodeIndex);

                trans = temp - position;
                setPosition(trans);

                NodeIndex++;
           
                if (NodeIndex >= VertAmount - 1) {
                    GoingBack = false;
                }
            }
            else if (NodeIndex >= 0 && !GoingBack) {
                glm::vec3 temp = grap->getVertexPosition(NodeIndex);

                trans = temp - position;

                setPosition(trans);

                NodeIndex--;
            
                if (NodeIndex <= 0) {
                    NodeIndex = 0;
                    GoingBack = true;
                }
            }
            seconds = 0.0f;
        }
    }
};

