#pragma once

#include "Obstacle.h"

class Corridor : public Obstacle {
public:
	Corridor(MeshType type, const glm::vec3 &pos, bool generate_obstacles = true);
	~Corridor();
	glm::vec3 GetEndPos();
private:
	Obstacle* GenerateObstacle(const glm::vec3& pos);
};

class ForkCorridor : public Corridor {
public:
	ForkCorridor(const glm::vec3& pos);
	glm::vec3 GetLeftEndPos();
	glm::vec3 GetRightEndPos();
};