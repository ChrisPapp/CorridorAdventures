#pragma once
#pragma once

#include "Entity.h"
#include <unordered_set>

class Obstacle {
public:
	Obstacle(MeshType type, const glm::vec3& pos, const glm::mat4 &mat = glm::mat4(1.f));
	virtual ~Obstacle();
	virtual bool Update(float dt);
protected:
	Entity* m_entity;
	glm::vec3 m_pos;
	MeshType m_type;

	typedef std::unordered_set<Obstacle*> ObstacleContainer;
	ObstacleContainer children;
};