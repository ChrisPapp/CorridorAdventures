#pragma once

#include "Obstacle.h"

class Corridor : public Obstacle {
public:
	Corridor(MeshType type, const glm::vec3 &pos);
	~Corridor();
	glm::vec3 GetEndPos();
protected:
};

class ForkCorridor : public Corridor {
public:
	ForkCorridor(const glm::vec3& pos);
	glm::vec3 GetLeftEndPos();
	glm::vec3 GetRightEndPos();
};