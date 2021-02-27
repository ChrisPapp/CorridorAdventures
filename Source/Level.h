#pragma once
#include <vector>
#include "glm/vec3.hpp"
#include "Corridor.h"

enum Direction {
	straight,
	left,
	right
};

struct CorridorTree {
	std::vector<enum Direction> path;
	CorridorTree* left;
	CorridorTree* right;

	~CorridorTree() {
		delete left;
		delete right;
	}
};

class Level {
public:
	Level(CorridorTree& root, const glm::vec3 &start_pos = glm::vec3(0.f));
	~Level();
	bool Update(float dt);
private:
	void BuildLevel(CorridorTree& root, const glm::vec3& start_pos);
	typedef std::vector<Corridor*> VectorContainer;
	VectorContainer corridors;
};