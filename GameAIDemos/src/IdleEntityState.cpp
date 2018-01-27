#include "../include/IdleEntityState.hpp"

GameAIDemos::IdleEntityState::IdleEntityState() :
	BaseEntityState("Idle"), m_sourcePtr(nullptr)
{
	// We need an empty constructor for Entity... this needs fixing (TODO)
}

GameAIDemos::IdleEntityState::IdleEntityState(LiveEntity* source) :
	BaseEntityState("Idle"), m_sourcePtr(source)
{
	enter();
}

void GameAIDemos::IdleEntityState::enter()
{
	// m_sourcePtr->setSpriteColor(sf::Color::Yellow);
	// Set entity sprite color to a purple-ish color
	m_sourcePtr->setSpriteColor(sf::Color(169, 20, 255));
}

void GameAIDemos::IdleEntityState::update()
{
	// Nothing to do here, entity is idling...
}

void GameAIDemos::IdleEntityState::exit()
{
	// Not sure what could go here, normally other states kick the entity
	// out of idle by, for example, setting their velocity
}

GameAIDemos::BaseEntityState* GameAIDemos::IdleEntityState::getNewState()
{
	return nullptr;
}
