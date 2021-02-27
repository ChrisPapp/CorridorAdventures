#include <algorithm>
#include "Level.h"

Level::Level(CorridorTree &root, const glm::vec3 &start_pos)
{
	BuildLevel(root, start_pos);
}

Level::~Level()
{
	std::for_each(corridors.begin(), corridors.end(), [](Corridor* corridor) { delete corridor; });
}

void Level::BuildLevel(CorridorTree& root, const glm::vec3& start_pos)
{
	glm::vec3 curr_pos = start_pos;
	Corridor* curr_corridor = nullptr;
	for (Direction dir : root.path) {
		switch (dir) {
		case straight:
			curr_corridor = new Corridor(CORRIDOR_S, curr_pos);
			break;
		case left:
			curr_corridor = new Corridor(CORRIDOR_L, curr_pos);
			break;
		case right:
			curr_corridor = new Corridor(CORRIDOR_R, curr_pos);
			break;
		default:
			assert(false);
			break;
		}
		if (curr_corridor) {
			corridors.push_back(curr_corridor);
			curr_pos = curr_corridor->GetEndPos();
		}
	}
	if (root.left || root.right) {
		ForkCorridor *fork_corr = new ForkCorridor(curr_pos);
		corridors.push_back(fork_corr);
		if (root.left)
			BuildLevel(*root.left, fork_corr->GetLeftEndPos());
		if (root.right)
			BuildLevel(*root.right, fork_corr->GetRightEndPos());

	}
}

bool Level::Update(float dt)
{
	return std::all_of(corridors.begin(), corridors.end(), [dt](Corridor* corr) {return corr->Update(dt);});
}