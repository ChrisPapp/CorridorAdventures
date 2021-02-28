#include "Wall.h"
#include "Cannon.h"
#include "glm/gtc/matrix_transform.hpp"

constexpr glm::vec3 lower_hole_offset = glm::vec3(0, -3, 0), upper_hole_offset = glm::vec3(0, 3, 0);

Wall::Wall(const glm::mat4 &transform) : Obstacle(WALL, transform)
{
	children.insert(new Cannon(glm::translate(transform, lower_hole_offset)));
	children.insert(new Obstacle(MeshType::IRIS, glm::translate(transform, upper_hole_offset)));
}