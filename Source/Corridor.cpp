#pragma once
#include "Corridor.h"
#include "Game.h"
#include "Wall.h"
#include "glm/gtc/matrix_transform.hpp"
#include <cstdlib>


constexpr float corridor_legth = 20.f, corridor_width = 10.f;
constexpr glm::vec3 obstacle_offset = glm::vec3(0, 0, -10.f);

Corridor::Corridor(MeshType type, const glm::vec3 &pos, bool generate_obstacles) : Obstacle(type, glm::translate(glm::mat4(1.f), pos))
{
	if (!generate_obstacles) // Don't generate any obstacles
		return;
	children.insert(GenerateObstacle(pos + obstacle_offset));
}

Corridor::~Corridor()
{
}

glm::vec3 Corridor::GetEndPos()
{
	glm::vec3 end_pos = m_entity->GetPosition();
	end_pos.z -= corridor_legth;
	switch (m_entity->m_type) {
	case CORRIDOR_L:
		end_pos.x -= corridor_width / 2.f;
		break;
	case CORRIDOR_R:
		end_pos.x += corridor_width / 2.f;
		break;
	case CORRIDOR_S:
		break;
	default:
		assert(false);
		break;
	}
	return end_pos;
}

enum ObstacleType {
	OT_WALL,
	OT_BEAM,
	OT_PIPE,
	OT_SIZE,
};

Obstacle* Corridor::GenerateObstacle(const glm::vec3& pos)
{
	int random = std::rand();
	bool transform_obstacle = std::rand() % 2 == 0; // Randomly transform obstacle
	enum ObstacleType type = static_cast<ObstacleType>(random % ObstacleType::OT_SIZE); // Random type
	glm::mat4 transform(1.f); // Entity transformations
	glm::vec3 entity_pos(pos); // Relative entity position
	switch (type) {
	case OT_WALL:
		if (transform_obstacle) {
			int sign = std::rand() % 2 ? 1 : -1;
			entity_pos = entity_pos + glm::vec3(0, sign * 4, 0);
			transform = glm::translate(transform, entity_pos);
			transform = glm::rotate(transform, glm::radians(90.f), glm::vec3(sign * 1, 0, 0));
		} else {
			transform = glm::translate(transform, entity_pos);
		}
		return new Wall(transform);
		break;
	case OT_BEAM:
		entity_pos += glm::vec3(0, 3, 0);
		transform = glm::translate(transform, entity_pos);
		if (transform_obstacle)
		 	transform = glm::rotate(transform, glm::radians(90.f), glm::vec3(1, 0, 0));
		return new Obstacle(MeshType::BEAM, transform);
		break;
	case OT_PIPE:
		entity_pos += glm::vec3(2., 2., 0);
		if (transform_obstacle) {
			transform = glm::translate(transform, entity_pos + glm::vec3(5, 0, 0));
			transform = glm::rotate(transform, glm::radians(90.f), glm::vec3(0, 1, 0));
		} else {
			transform = glm::translate(transform, entity_pos);
		}
		return new Obstacle(MeshType::PIPE, transform);
		break;
	default:
		assert(false);
		return nullptr;
	}
}



// FORK CORRIDOR

ForkCorridor::ForkCorridor(const glm::vec3 &pos) : Corridor(MeshType::CORRIDOR_F, pos, false)
{
	children.insert(new Obstacle(MeshType::BEAM, glm::translate(glm::rotate(glm::mat4(1.f), glm::radians(90.f), glm::vec3(0, 0, -1)), glm::vec3(0, 0, -corridor_legth * 0.75))));
}

glm::vec3 ForkCorridor::GetLeftEndPos()
{
	return this->m_entity->GetPosition() + glm::vec3(-corridor_width / 2.f, 0, -corridor_legth);
}

glm::vec3 ForkCorridor::GetRightEndPos()
{
	return this->m_entity->GetPosition() + glm::vec3(corridor_width / 2.f, 0, -corridor_legth);
}