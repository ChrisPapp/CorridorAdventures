#include "Wall.h"
#include "Cannon.h"

constexpr glm::vec3 lower_hole_offset = glm::vec3(0, -3, 0), upper_hole_offset = glm::vec3(0, 3, 0);

Wall::Wall(const glm::vec3& pos, const glm::mat4 &transform) : Obstacle(WALL, pos, transform)
{
	children.insert(new Cannon(pos + lower_hole_offset, transform));
	children.insert(new Obstacle(MeshType::IRIS, pos + upper_hole_offset, transform));
}