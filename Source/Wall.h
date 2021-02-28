#pragma once
#include "Obstacle.h"

class Wall : public Obstacle {
public:
	Wall(const glm::mat4 &transform = glm::mat4(1.f));
};