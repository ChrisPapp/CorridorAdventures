#pragma once

#include "GeometryNode.h"
#include "CollidableNode.h"

enum MeshType
{
	CORRIDOR_L = 0,
	CORRIDOR_R,
	CORRIDOR_F,
	CORRIDOR_S,
	WALL,
	SIZE_ALL
};

class Entity {
public:

	GeometryNode& GetDrawnGeometry() { return drawnGeom; };
	CollidableNode& GetCollidableGeometry() { return collisionGeom; };

	void SetPosition(const glm::vec3 &pos);
	virtual bool Update();
private:
	friend class Game;
	Entity(enum MeshType type, const glm::vec3 &pos = glm::vec3(0.f));
	GeometryNode drawnGeom;
	CollidableNode collisionGeom;
};