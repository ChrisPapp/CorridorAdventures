#pragma once
#include "Obstacle.h"

class Wall : public Obstacle {
public:
	Wall(const glm::vec3& pos);
};