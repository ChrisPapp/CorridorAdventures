#pragma once

#include <unordered_set>
#include <unordered_map>

#include "Entity.h"
#include "GeometricMesh.h"

class MeshManager {

public:
	MeshManager();
	// get the static instance of Texture Manager
	static MeshManager& Get()
	{
		static MeshManager manager;
		return manager;
	}
	GeometricMesh* GetMesh(MeshType type);
	GeometricMesh* GetCollisionMesh(enum MeshType type);
	bool Init();
	void Clear();
private:
	OBJLoader loader;
	std::unordered_map<MeshType, GeometricMesh*> draw_meshes, collision_meshes;
};