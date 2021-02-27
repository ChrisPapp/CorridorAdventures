#include "MeshManager.h"
#include "Entity.h"

static std::unordered_map<MeshType, const char*> mesh_paths = {
	{MeshType::CORRIDOR_L, "Assets/scene/Corridor_Left.obj"},
	{MeshType::CORRIDOR_R, "Assets/scene/Corridor_Right.obj"},
	{MeshType::CORRIDOR_F, "Assets/scene/Corridor_Fork.obj"},
	{MeshType::CORRIDOR_S, "Assets/scene/Corridor_Straight.obj"},
	{MeshType::WALL, "Assets/scene/Wall.obj"},
};

static std::unordered_map<MeshType, const char*> collidable_paths = {
	{MeshType::CORRIDOR_L, "Assets/scene/CH-Corridor_Left.obj"},
	{MeshType::CORRIDOR_R, "Assets/scene/CH-Corridor_Right.obj"},
	{MeshType::CORRIDOR_F, "Assets/scene/CH-Corridor_Fork.obj"},
	{MeshType::CORRIDOR_S, "Assets/scene/CH-Corridor_Straight.obj"},
	{MeshType::WALL, "Assets/scene/CH-Wall.obj"},
};

MeshManager::MeshManager()
{
}

bool MeshManager::Init()
{
	// Load and cache all meshes
	for (int i = 0; i < MeshType::SIZE_ALL; i++) {
		MeshType type = static_cast<MeshType>(i);
		if (!GetMesh(type) || !GetCollisionMesh(type))
			return false;
	}
	return true;
}

void MeshManager::Clear()
{
	// Clear cached meshes
	std::for_each(draw_meshes.begin(), draw_meshes.end(), [](std::pair<MeshType, GeometricMesh*> pair) { delete pair.second; });
	draw_meshes.clear();
	std::for_each(collision_meshes.begin(), collision_meshes.end(), [](std::pair<MeshType, GeometricMesh*> pair) { delete pair.second; });
	collision_meshes.clear();
}


GeometricMesh* MeshManager::GetMesh(enum MeshType type)
{
	auto it = this->draw_meshes.find(type);
	if (it != draw_meshes.end()) {
		return it->second;
	}
	else {
		GeometricMesh *mesh = loader.load(mesh_paths[type]);
		if (!mesh)
			return nullptr;
		draw_meshes[type] = mesh;
		return mesh;
	}
}

GeometricMesh* MeshManager::GetCollisionMesh(enum MeshType type)
{
	auto it = this->collision_meshes.find(type);
	if (it != this->collision_meshes.end()) {
		return it->second;
	}
	else {
		GeometricMesh* mesh = loader.load(collidable_paths[type]);
		if (!mesh)
			return nullptr;
		collision_meshes[type] = mesh;
		return mesh;
	}
}
