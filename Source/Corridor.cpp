#pragma once
#include "Corridor.h"
#include "Game.h"

Corridor::Corridor(MeshType type, const glm::vec3 &pos)
{
	m_corridor = Game::Get().AddEntity(type, pos);
	m_wall = Game::Get().AddEntity(MeshType::WALL, pos + glm::vec3(0, 0, -3));
}

Corridor::~Corridor()
{
	Game::Get().DeleteEntity(m_corridor);
	Game::Get().DeleteEntity(m_wall);
}