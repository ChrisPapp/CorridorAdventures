#include <algorithm>
#include "Entity.h"
#include "Game.h"
#include "glm/gtc/matrix_transform.hpp"
#include "MeshManager.h"

Entity::Entity(enum MeshType type)
{
	m_type = type;
}

glm::vec3 Entity::GetPosition()
{
	return glm::vec3(this->model_matrix[3]);
}

void Entity::SetTransform(const glm::mat4& mat)
{
	this->model_matrix = mat;
}

bool Entity::Update(float dt)
{
	constexpr float collision_distance = 3.f;
	std::vector<glm::vec3> dirs = { glm::vec3(0, 0, -1), glm::vec3(0, 1, -1), glm::vec3(0, -1, -1), glm::vec3(1, 0, -1), glm::vec3(-1, 0, -1) };
	return std::all_of(dirs.begin(), dirs.end(), [this](const glm::vec3& dir) {
		// Cast rays to every direction. All intersection must be further than 'collision_distance'
		float dist;
		const glm::vec3& player_pos = Game::Get().GetPlayerPos();
		if (!this->GetCollidableGeometry().intersectRay(player_pos, dir, dist, this->GetModelMatrix()))
			return true;
		return dist > collision_distance;
	});
}

GeometryNode& Entity::GetDrawnGeometry()
{
	GeometryNode* node = MeshManager::Get().GetNode(m_type);
	assert(node);
	return *node;
}

CollidableNode& Entity::GetCollidableGeometry()
{
	CollidableNode* node = MeshManager::Get().GetCollisionNode(m_type);
	assert(node);
	return *node;
}