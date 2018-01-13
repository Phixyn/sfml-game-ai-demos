#include "../include/DeadEntityState.hpp"

GameAIDemos::DeadEntityState::DeadEntityState() : BaseEntityState("Dead")
{
}

void GameAIDemos::DeadEntityState::enter()
{
}

void GameAIDemos::DeadEntityState::update()
{
}

void GameAIDemos::DeadEntityState::exit()
{
}

GameAIDemos::BaseEntityState* GameAIDemos::DeadEntityState::getNewState()
{
	return nullptr;
}
