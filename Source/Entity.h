#pragma once

#include "GeometryNode.h"
#include "CollidableNode.h"

class Entity {

	Entity(enum MeshType type);

private:

	GeometryNode drawnGeom;
	CollidableNode collisionGeom;
};