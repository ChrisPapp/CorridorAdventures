#pragma once

#include "Entity.h"

class Corridor {
public:
	Corridor(MeshType type, const glm::vec3 &pos);
	~Corridor();
	bool Update(float dt);
	glm::vec3 GetEndPos();
protected:
	Entity *m_corridor, *m_wall;
	glm::vec3 m_pos;
	MeshType m_type;
};

class ForkCorridor : public Corridor {
public:
	ForkCorridor(const glm::vec3& pos);
	glm::vec3 GetLeftEndPos();
	glm::vec3 GetRightEndPos();
};