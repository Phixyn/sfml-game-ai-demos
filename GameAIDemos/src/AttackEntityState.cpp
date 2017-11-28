#include "../include/AttackEntityState.hpp"

GameAIDemos::AttackEntityState::AttackEntityState() : BaseEntityState("Attacking")
{
}

void GameAIDemos::AttackEntityState::enter()
{
}

void GameAIDemos::AttackEntityState::update()
{
}

void GameAIDemos::AttackEntityState::exit()
{
}

GameAIDemos::BaseEntityState* GameAIDemos::AttackEntityState::getNewState()
{
	return nullptr;
}
