#include "MeshManager.h"
#include "Entity.h"

static std::unordered_map<MeshType, const char*> mesh_paths = {
	{MeshType::CORRIDOR_L, "Assets/scene/Corridor_Left.obj"},
	{MeshType::CORRIDOR_R, "Assets/scene/Corridor_Right.obj"},
	{MeshType::CORRIDOR_F, "Assets/scene/Corridor_Fork.obj"},
	{MeshType::CORRIDOR_S, "Assets/scene/Corridor_Straight.obj"},
	{MeshType::CANNON_MOUNT, "Assets/scene/CannonMount.obj"},
	{MeshType::TURRET, "Assets/scene/Cannon.obj"},
	{MeshType::BEAM, "Assets/scene/Beam.obj"},
	{MeshType::PIPE, "Assets/scene/Pipe.obj"},
	{MeshType::IRIS, "Assets/scene/Iris.obj"},
	{MeshType::WALL, "Assets/scene/Wall.obj"},
};

static std::unordered_map<MeshType, const char*> collidable_paths = {
	{MeshType::CORRIDOR_L, "Assets/scene/CH-Corridor_Left.obj"},
	{MeshType::CORRIDOR_R, "Assets/scene/CH-Corridor_Right.obj"},
	{MeshType::CORRIDOR_F, "Assets/scene/CH-Corridor_Fork.obj"},
	{MeshType::CORRIDOR_S, "Assets/scene/CH-Corridor_Straight.obj"},
	{MeshType::CANNON_MOUNT, "Assets/scene/CH-CannonMount.obj"},
	{MeshType::TURRET, "Assets/scene/CH-Cannon.obj"},
	{MeshType::BEAM, "Assets/scene/CH-Beam.obj"},
	{MeshType::PIPE, "Assets/scene/CH-Pipe.obj"},
	{MeshType::IRIS, "Assets/scene/CH-Iris.obj"},
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
		if (!GetNode(type) || !GetCollisionNode(type))
			return false;
	}
	return true;
}

void MeshManager::Clear()
{
	// Clear cached meshes
	std::for_each(draw_meshes.begin(), draw_meshes.end(), [](std::pair<MeshType, GeometryNode*> pair) { delete pair.second; });
	draw_meshes.clear();
	std::for_each(collision_meshes.begin(), collision_meshes.end(), [](std::pair<MeshType, CollidableNode*> pair) { delete pair.second; });
	collision_meshes.clear();
}


GeometryNode* MeshManager::GetNode(enum MeshType type)
{
	auto it = this->draw_meshes.find(type);
	if (it != draw_meshes.end()) {
		return it->second;
	}
	else {
		GeometricMesh* mesh = loader.load(mesh_paths[type]);
		GeometryNode* node = new GeometryNode();
		if (!mesh)
			return nullptr;
		node->Init(mesh);
		draw_meshes[type] = node;
		delete mesh;
		return node;
	}
}

CollidableNode* MeshManager::GetCollisionNode(enum MeshType type)
{
	auto it = this->collision_meshes.find(type);
	if (it != this->collision_meshes.end()) {
		return it->second;
	}
	else {
		GeometricMesh* mesh = loader.load(collidable_paths[type]);
		if (!mesh)
			return nullptr;
		CollidableNode* node = new CollidableNode();
		node->Init(mesh);
		collision_meshes[type] = node;
		delete mesh;
		return node;
	}
}
