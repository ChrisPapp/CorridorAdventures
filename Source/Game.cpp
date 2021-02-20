#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Game.h"
#include "SDL2/SDL.h"
#include "Renderer.h"
#include "MeshManager.h"

void Game::Init()
{
	Entity* wall = new Entity(MeshType::WALL);
	entities.insert(wall);
	wall->GetDrawnGeometry().app_model_matrix =
		glm::translate(glm::mat4(1.f), wall->GetDrawnGeometry().m_aabb.center) *
		wall->GetDrawnGeometry().model_matrix;
}

Game::~Game()
{
	std::for_each(entities.begin(), entities.end(), [](Entity* entity) { delete entity; });
}

void Game::Update(float delta_time)
{

}
