#include "Game.h"
#include "SDL2/SDL.h"
#include "Renderer.h"

EntityContainerCIterator Game::EntitiesBegin()
{
	return this->entities.cbegin();
}

EntityContainerCIterator Game::EntitiesEnd()
{
	return this->entities.cend();
}

void Game::Update(float delta_time)
{

}
