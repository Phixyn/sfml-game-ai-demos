#include "../include/SeekEntityState.hpp"

GameAIDemos::SeekEntityState::SeekEntityState(LiveEntity* source, PlayerEntity& target) :
	BaseEntityState("Seeking"), m_sourcePtr(source), m_playerPtr(&target)
{
	enter();
}

void GameAIDemos::SeekEntityState::enter()
{
	m_sourcePtr->setSpriteColor(sf::Color::Green);
}

void GameAIDemos::SeekEntityState::update()
{
	// m_sourcePtr->setAcceleration(sf::Vector2f(0.0f, 0.0f));
	sf::Vector2f acceleration = sf::Vector2f(0.0f, 0.0f);
	sf::Vector2f steer = sf::Vector2f(0.0f, 0.0f);

	// Position of target we're seeking
	sf::Vector2f targetPos = m_playerPtr->getPosition();
	// Our position
	sf::Vector2f sourcePos = m_sourcePtr->getPosition();
	// Our direction
	sf::Vector2f direction = targetPos - sourcePos;
	// Normalize direction vector
	float normDirection = sqrt((direction.x * direction.x) + (direction.y * direction.y));
	direction /= normDirection;

	// Calculate steering force
	steer += direction;
	// TODO: comments
	steer /= 1.0f;
	// Steering magnitude (steering vector normalized)
	float normSteer = sqrt((steer.x * steer.x) + (steer.y * steer.y));
	steer /= normSteer;
	steer *= normSteer;
	steer -= m_sourcePtr->getVelocity();
	acceleration += steer;

	// Calculate velocity required
	m_sourcePtr->setVelocity(m_sourcePtr->getVelocity() + acceleration);
	float normVelocity = sqrt((m_sourcePtr->getVelocity().x * m_sourcePtr->getVelocity().x) + (m_sourcePtr->getVelocity().y * m_sourcePtr->getVelocity().y));
	m_sourcePtr->setVelocity(m_sourcePtr->getVelocity() / normVelocity);
	m_sourcePtr->setVelocity(m_sourcePtr->getVelocity() * m_sourcePtr->getMaxSpeed());

	m_sourcePtr->setPosition(sourcePos + m_sourcePtr->getVelocity());

	// TODO We must also move the associated InfoPanel
	// m_sourcePtr->getInfoPanel().setPanelPosition(m_sourcePtr->getInfoPanel().getPanelPosition() + m_sourcePtr->getVelocity());
}

void GameAIDemos::SeekEntityState::exit()
{
	m_sourcePtr->setVelocity(sf::Vector2f(0.0f, 0.0f));
}

GameAIDemos::BaseEntityState* GameAIDemos::SeekEntityState::getNewState()
{
	return nullptr;
}
