#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "SDL2/SDL.h"
#include "Renderer.h"
#include "MeshManager.h"
#include "Game.h"

void Game::Init()
{
	CorridorTree tree{ {straight, left, right, straight},/* new CorridorTree({{left, straight}}), new CorridorTree({{right, straight}})*/ };
	this->level = new Level(tree);
}

Game::~Game()
{
	delete level;
	std::for_each(entities.begin(), entities.end(), [](Entity* entity) { delete entity; });
}

void Game::Update(float delta_time)
{
	if (!this->level->Update(delta_time))
		is_hit = true;
}

Entity *Game::AddEntity(MeshType type, const glm::vec3& pos, const glm::mat4 &transform)
{
	Entity* entity = new Entity(type, pos);
	entity->SetTransform(glm::translate(transform, pos));
	entities.insert(entity);
	return entity;
}

void Game::DeleteEntity(Entity* entity)
{
	entities.erase(entity);
	delete entity;
}