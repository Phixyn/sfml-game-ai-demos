#include "../include/DefendEntityState.hpp"

GameAIDemos::DefendEntityState::DefendEntityState() : BaseEntityState("Defending")
{	
}

void GameAIDemos::DefendEntityState::enter()
{
}

void GameAIDemos::DefendEntityState::update()
{
}

void GameAIDemos::DefendEntityState::exit()
{
}

GameAIDemos::BaseEntityState* GameAIDemos::DefendEntityState::getNewState()
{
	return nullptr;
}
