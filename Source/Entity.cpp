#include "Entity.h"
#include "MeshManager.h"

Entity::Entity(enum MeshType type, const glm::vec3 &pos)
{
	GeometricMesh * mesh = MeshManager::Get().GetMesh(type);
	this->drawnGeom.Init(mesh);
	mesh = MeshManager::Get().GetCollisionMesh(type);
	this->collisionGeom.Init(mesh);

	this->SetPosition(pos);
}

void Entity::SetPosition(const glm::vec3& pos)
{
	this->drawnGeom.SetPosition(pos);
	this->collisionGeom.SetPosition(pos);
}

bool Entity::Update()
{
	return true;
}