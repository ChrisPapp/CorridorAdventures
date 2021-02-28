#pragma once
#include "Corridor.h"
#include "Game.h"


constexpr float corridor_legth = 20.f, corridor_width = 10.f;

Corridor::Corridor(MeshType type, const glm::vec3 &pos)
{
	m_type = type;
	m_corridor = Game::Get().AddEntity(type, pos);
	m_wall = Game::Get().AddEntity(MeshType::WALL, pos + glm::vec3(0, 0, -3));
	m_pos = pos;
}

Corridor::~Corridor()
{
	Game::Get().DeleteEntity(m_corridor);
	Game::Get().DeleteEntity(m_wall);
}

bool Corridor::Update(float dt)
{
	return m_corridor->Update(dt) && m_wall->Update(dt);
}

glm::vec3 Corridor::GetEndPos()
{
	glm::vec3 end_pos = m_pos;
	end_pos.z -= corridor_legth;
	switch (m_type) {
	case CORRIDOR_L:
		end_pos.x -= corridor_width / 2.f;
		break;
	case CORRIDOR_R:
		end_pos.x += corridor_width / 2.f;
		break;
	case CORRIDOR_S:
		break;
	default:
		assert(false);
		break;
	}
	return end_pos;
}


// FORK CORRIDOR

ForkCorridor::ForkCorridor(const glm::vec3 &pos) : Corridor(CORRIDOR_F, pos)
{
}

glm::vec3 ForkCorridor::GetLeftEndPos()
{
	return this->m_pos + glm::vec3(-corridor_width / 2.f, 0, -corridor_legth);
}

glm::vec3 ForkCorridor::GetRightEndPos()
{
	return this->m_pos + glm::vec3(corridor_width / 2.f, 0, -corridor_legth);
}