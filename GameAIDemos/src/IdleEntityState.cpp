#include "../include/IdleEntityState.hpp"

GameAIDemos::IdleEntityState::IdleEntityState() : BaseEntityState("Idle")
{
	
}

void GameAIDemos::IdleEntityState::enter()
{
}

void GameAIDemos::IdleEntityState::update()
{
}

void GameAIDemos::IdleEntityState::exit()
{
}

GameAIDemos::BaseEntityState* GameAIDemos::IdleEntityState::getNewState()
{
	return nullptr;
}
