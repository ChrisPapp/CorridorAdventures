#include "Entity.h"
#include "MeshManager.h"

Entity::Entity(enum MeshType type)
{
	GeometricMesh * mesh = MeshManager::Get().GetMesh(type);
	this->drawnGeom.Init(mesh);
	mesh = MeshManager::Get().GetCollisionMesh(type);
	this->collisionGeom.Init(mesh);
}