#pragma once



#include "positionComponent.h"

class moveComponent : public PositionComponent {
	
	// Keyboard
	enum Direction { 
		// X
		LEFT,
		RIGHT,
		// Y
		UP,
		DOWN,
		// Z
		FORWARD,
		BACKWARD
	};

	void localMove(Direction direction, float deltaTime);
	void worldMove(Direction direction, float deltaTime);
	float moveSpeed{};
	bool useLocal{ true };

};

