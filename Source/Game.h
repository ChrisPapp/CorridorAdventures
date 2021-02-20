#pragma once

#include "Entity.h"
#include <unordered_set>

constexpr int SCREEN_WIDTH = 1024;
constexpr int SCREEN_HEIGHT = 860;

typedef std::unordered_set<Entity*> EntityContainer;
typedef EntityContainer::iterator EntityContainerIterator;

class Game {

public:
	// Game is a singleton. Get the game instance
	static Game& Get()
	{
		static Game game;
		return game;
	}

	~Game();

	EntityContainerIterator begin() { return entities.begin(); };
	EntityContainerIterator end() { return entities.end(); };

	void Update(float delta_time);
	void Init();

private:
	EntityContainer entities;
};
