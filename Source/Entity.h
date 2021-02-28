#pragma once

#include "GeometryNode.h"
#include "CollidableNode.h"

enum MeshType
{
	CORRIDOR_L = 0,
	CORRIDOR_R,
	CORRIDOR_F,
	CORRIDOR_S,
	CANNON_MOUNT,
	TURRET,
	IRIS,
	PIPE,
	BEAM,
	WALL,
	SIZE_ALL
};

class Entity {
public:

	GeometryNode& GetDrawnGeometry();
	CollidableNode& GetCollidableGeometry();

	void SetPosition(const glm::vec3 &pos);
	void SetTransform(const glm::mat4& transform);
	virtual bool Update(float dt);
	virtual glm::mat4 GetInitialModelMatrix() { return glm::mat4(1.f); };
	glm::mat4& GetModelMatrix() { return model_matrix; };
	glm::vec3 position;
	MeshType m_type;
private:
	friend class Game;
	Entity(enum MeshType type, const glm::vec3 &pos = glm::vec3(0.f));
	glm::mat4 model_matrix;
};