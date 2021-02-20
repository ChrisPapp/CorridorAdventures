#pragma once

#include "GeometryNode.h"
#include "CollidableNode.h"

class Entity {

public:
	Entity(enum MeshType type);

	GeometryNode& GetDrawnGeometry() { return drawnGeom; };
	CollidableNode& GetCollidableGeometry() { return collisionGeom; };
private:

	GeometryNode drawnGeom;
	CollidableNode collisionGeom;
};