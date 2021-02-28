#include "Obstacle.h"
#include "Game.h"
#include <algorithm>

Obstacle::Obstacle(MeshType type, const glm::mat4& transform)
{
	m_entity = Game::Get().AddEntity(type, transform);
}

Obstacle::~Obstacle()
{
	Game::Get().DeleteEntity(m_entity);
	std::for_each(children.begin(), children.end(), [](Obstacle* ob) { delete ob; });
}

bool Obstacle::Update(float dt)
{
	constexpr float player_min_dist = 10.f;
	// Don't run collision check if player is far away
	glm::vec3 player_pos = Game::Get().GetPlayerPos();
	if (player_pos.z + player_min_dist < this->m_entity->GetPosition().z || this->m_entity->GetPosition().z + player_min_dist < player_pos.z)
		return true;
	if (!m_entity->Update(dt))
		return false;
	return std::all_of(children.begin(), children.end(), [dt](Obstacle* ob) { return ob->Update(dt);});
}