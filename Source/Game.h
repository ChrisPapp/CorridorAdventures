#pragma once

#include "Entity.h"
#include <set>


constexpr int SCREEN_WIDTH = 1024;
constexpr int SCREEN_HEIGHT = 860;

typedef std::set<Entity> EntityContainer;
typedef EntityContainer::const_iterator EntityContainerCIterator;

enum MeshType
{
	BALL = 0,
	CHAIR,
	FLOOR,
	WALLS,
	SIZE_ALL
};

class Game {

public:
	// Game is a singleton. Get the game instance
	static Game& Get()
	{
		static Game game;
		return game;
	}


	EntityContainerCIterator EntitiesBegin();
	EntityContainerCIterator EntitiesEnd();

	void Update(float delta_time);

private:
	EntityContainer entities;
};
