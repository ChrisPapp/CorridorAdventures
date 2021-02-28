#pragma once
#pragma once

#include "Entity.h"
#include <unordered_set>

class Obstacle {
public:
	Obstacle(MeshType type, const glm::mat4 &transform = glm::mat4(1.f));
	virtual ~Obstacle();
	virtual bool Update(float dt);
protected:
	Entity* m_entity;

	typedef std::unordered_set<Obstacle*> ObstacleContainer;
	ObstacleContainer children;
};