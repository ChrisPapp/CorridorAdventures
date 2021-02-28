#pragma once

#include "Entity.h"
#include "Corridor.h"
#include "Level.h"
#include <unordered_set>

constexpr int SCREEN_WIDTH = 1024;
constexpr int SCREEN_HEIGHT = 860;

class Game {
	typedef std::unordered_set<Entity*> EntityContainer;
	typedef EntityContainer::iterator EntityContainerIterator;
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
	Entity* AddEntity(MeshType type, const glm::vec3& pos, const glm::mat4 &transform = glm::mat4(1.f));
	void DeleteEntity(Entity* entity);

	EntityContainerIterator begin() { return entities.begin(); };
	EntityContainerIterator end() { return entities.end(); };

	void SetPlayerPos(const glm::vec3& pos) { this->player_pos = pos; };
	const glm::vec3& GetPlayerPos() { return this->player_pos; };

private:
	EntityContainer entities;

	glm::vec3 player_pos;
	
	Level* level;
};
