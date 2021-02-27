#include <algorithm>
#include "Entity.h"
#include "MeshManager.h"
#include "Game.h"

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

bool Entity::Update(float dt)
{
	constexpr float collision_distance = 2.f;
	std::vector<glm::vec3> dirs = { glm::vec3(0, 0, -1), glm::vec3(0, 1, -1), glm::vec3(0, -1, -1), glm::vec3(1, 0, -1), glm::vec3(-1, 0, -1) };
	return std::all_of(dirs.begin(), dirs.end(), [this](const glm::vec3& dir) {
		// Cast rays to every direction. All intersection must be further than 'collision_distance'
		float dist;
		const glm::vec3& player_pos = Game::Get().GetPlayerPos();
		if (!this->GetCollidableGeometry().intersectRay(player_pos, dir, dist))
			return true;
		return dist > collision_distance;
	});
}