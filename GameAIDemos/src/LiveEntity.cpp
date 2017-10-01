#include "../include/LiveEntity.hpp"

/// <summary>
/// Calls the superclass constructor and initializes member variables.
/// </summary>
GameAIDemos::LiveEntity::LiveEntity(int health, sf::Vector2f position) :
	Entity(position), m_velocity(0.0f, 0.0f), m_health(health)
{
	// TODO: give entities unique IDs and include this in log statement below
	m_logger.log("DEBUG", "Initializing a live entity.");
}

GameAIDemos::LiveEntity::LiveEntity(int health, sf::Vector2f position, float speed) :
	Entity(position), m_velocity(0.0f, 0.0f), m_health(health), m_speed(speed)
{
	m_logger.log("DEBUG", "Initializing a live entity.");
}

void GameAIDemos::LiveEntity::handleEvents()
{
	// TODO
}

void GameAIDemos::LiveEntity::update(float deltaTime)
{
	// TODO
}

void GameAIDemos::LiveEntity::draw()
{
	// TODO
}

/// <summary>
/// Takes a direction vector.
/// Adjusts the live entity's velocity based on the direction vector.
/// </summary>
void GameAIDemos::LiveEntity::onCollision(sf::Vector2f direction)
{
	// TODO: simplify if statements here
	// Handle X axis collision
	if (direction.x > 0.0f)
	{
		// Left-hand side collision
		m_velocity.x = 0.0f;
	}

	else if (direction.x < 0.0f)
	{
		// Right-hand side collision
		m_velocity.x = 0.0f;
	}

	// Handle Y axis collision
	if (direction.y > 0.0f)
	{
		// Top collision
		m_velocity.y = 0.0f;
	}

	else if (direction.y < 0.0f)
	{
		// Bottom collision
		m_velocity.y = 0.0f;
		/*
		// Entity is on the ground and may jump again
		m_canJump = true;
		*/
	}
}

bool GameAIDemos::LiveEntity::isAggressive()
{
	return m_aggressive;
}

bool GameAIDemos::LiveEntity::isDead()
{
	return m_dead;
}

void GameAIDemos::LiveEntity::setDead(bool dead)
{
	// TODO: give entities unique IDs and include this in log statement below
	m_logger.log("DEBUG", "Entity: setting m_dead.");
	m_dead = dead;
}

/* TODO not yet implemented
sf::Vector2f GameAIDemos::LiveEntity::getDirection()
{
return m_direction;
}

void GameAIDemos::LiveEntity::setDirection(sf::Vector2f direction)
{
m_direction = direction;
}
*/