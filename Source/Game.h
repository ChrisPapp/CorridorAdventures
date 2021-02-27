#pragma once

#include "Entity.h"
#include "Corridor.h"
#include <unordered_set>

constexpr int SCREEN_WIDTH = 1024;
constexpr int SCREEN_HEIGHT = 860;

class Game {
	typedef std::unordered_set<Entity*> EntityContainer;
	typedef EntityContainer::iterator EntityContainerIterator;
	typedef std::vector<Corridor*> VectorContainer;
public:
	// Game is a singleton. Get the game instance
	static Game& Get()
	{
		static Game game;
		return game;
	}

	~Game();

	void Update(float delta_time);
	void Init();
	Entity* AddEntity(MeshType type, const glm::vec3& pos);
	void DeleteEntity(Entity* entity);

	EntityContainerIterator begin() { return entities.begin(); };
	EntityContainerIterator end() { return entities.end(); };

private:
	EntityContainer entities;
	VectorContainer corridors;
};
