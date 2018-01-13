#include "../include/AttackEntityState.hpp"
#include "../include/IdleEntityState.hpp"

GameAIDemos::AttackEntityState::AttackEntityState() : BaseEntityState("Attacking")
{
}

GameAIDemos::AttackEntityState::AttackEntityState(LiveEntity* target) : AttackEntityState()
{
	m_target = target;
}

void GameAIDemos::AttackEntityState::enter()
{
}

void GameAIDemos::AttackEntityState::update()
{
	// m_target->setHealth(m_target->getHealth() - 1);
	// std::cout << m_target->getHealth() << std::endl;
	/*
	if (m_target->isDead())
	{
		exit();
	}
	*/
}

void GameAIDemos::AttackEntityState::exit()
{
	// TODO
	// delete m_target;
}

GameAIDemos::BaseEntityState* GameAIDemos::AttackEntityState::getNewState()
{
	return new IdleEntityState();
}
