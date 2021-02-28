#include "Cannon.h"
#include "glm/gtc/matrix_transform.hpp"

constexpr glm::vec3 right_mount_offset = glm::vec3(0.5f, 0.f, 1.3f), left_mount_offset = glm::vec3(-0.5f, 0.f, 1.3f);

Cannon::Cannon(const glm::vec3& pos, const glm::mat4& transform) : Obstacle(MeshType::CANNON_MOUNT, pos, transform)
{
	// It fits us better to rotate the cannon matrix so it is horizontally placed
	glm::mat4 mount_transform = glm::rotate(glm::mat4(1.f), glm::radians(-90.f), glm::vec3(1, 0, 0));
	m_entity->SetTransform(glm::translate(transform, pos) * mount_transform);
	// Cannons are too big to mount. Scale them down.
	glm::mat4 cannon_transform = glm::translate(transform, pos + right_mount_offset) * glm::scale(glm::mat4(1.f), glm::vec3(0.5));
	children.insert(new Turret(glm::vec3(0.f), cannon_transform));
	cannon_transform = glm::translate(transform, pos + left_mount_offset) * glm::scale(glm::mat4(1.f), glm::vec3(0.5));
	children.insert(new Turret(glm::vec3(0.f), cannon_transform));
}

Turret::Turret(const glm::vec3& pos, const glm::mat4& transform) : Obstacle(MeshType::TURRET, pos, transform)
{
}

bool Turret::Update(float dt)
{
	return true;
}