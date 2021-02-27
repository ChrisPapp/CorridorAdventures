#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "SDL2/SDL.h"
#include "Renderer.h"
#include "MeshManager.h"
#include "Game.h"

void Game::Init()
{
	corridors.push_back(new Corridor(MeshType::CORRIDOR_S, glm::vec3(0, 0, 0)));
	corridors.push_back(new Corridor(MeshType::CORRIDOR_L, glm::vec3(0, 0, -20)));
}

Game::~Game()
{
	std::for_each(corridors.begin(), corridors.end(), [](Corridor* corridor) { delete corridor; });
	std::for_each(entities.begin(), entities.end(), [](Entity* entity) { delete entity; });
}

void Game::Update(float delta_time)
{

}

Entity *Game::AddEntity(MeshType type, const glm::vec3& pos)
{
	Entity* entity = new Entity(type, pos);
	entities.insert(entity);
	return entity;
}

void Game::DeleteEntity(Entity* entity)
{
	entities.erase(entity);
	delete entity;
}