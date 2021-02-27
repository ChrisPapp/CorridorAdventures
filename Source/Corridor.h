#pragma once

#include "Entity.h"

class Corridor {
public:
	Corridor(MeshType type, const glm::vec3 &pos);
	~Corridor();
private:
	Entity *m_corridor, *m_wall;
	glm::vec3 pos;
};