#pragma once

#include <unordered_set>
#include <unordered_map>

#include "GeometricMesh.h"
#include "Entity.h"

class MeshManager {

public:
	MeshManager();
	// get the static instance of Texture Manager
	static MeshManager& Get()
	{
		static MeshManager manager;
		return manager;
	}
	GeometryNode* GetNode(enum MeshType type);
	CollidableNode* GetCollisionNode(enum MeshType type);
	bool Init();
	void Clear();
private:
	OBJLoader loader;
	std::unordered_map<MeshType, GeometryNode*> draw_meshes;
	std::unordered_map<MeshType, CollidableNode*> collision_meshes;
};