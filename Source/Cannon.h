#pragma once
#include "Obstacle.h"

class Cannon : public Obstacle {
public:
	Cannon(const glm::mat4& transform = glm::mat4(1.f));
};

class Turret : public Obstacle {
public:
	Turret(const glm::mat4 &transform = glm::mat4(1.f));
	bool Update(float dt) override;
};