#include "../include/LiveEntity.hpp"
#include "../include/DeadEntityState.hpp"
#include <sstream>

/// <summary>
/// Calls the superclass constructor and initializes member variables.
/// </summary>
GameAIDemos::LiveEntity::LiveEntity(int health, sf::Vector2f size, sf::Vector2f position) :
	Entity(size, position), m_health(health), m_velocity(0.0f, 0.0f)
{
	// TODO: give entities unique IDs and include this in log statement below
	m_logger.log("DEBUG", "Initializing a live entity.");
	// setSpriteColor(sf::Color::Red);
	std::ostringstream entityInfoSS;
	entityInfoSS << "State: " << getState()->getStateName() << "\nHealth: " << m_health << "\nPosX: " << getPosition().x << "\nPosY: " << getPosition().y << "\nVelocityX: " << m_velocity.x << "\nVelocityY: " << m_velocity.y;
	m_infoPanel.setTextString(entityInfoSS.str());
}

GameAIDemos::LiveEntity::LiveEntity(int health, sf::Vector2f size, sf::Vector2f position, float speed) :
	Entity(size, position), m_health(health), m_velocity(0.0f, 0.0f), m_speed(speed)
{
	m_logger.log("DEBUG", "Initializing a live entity.");
}

void GameAIDemos::LiveEntity::handleEvents(sf::Event sfEvent)
{
	// TODO
}

void GameAIDemos::LiveEntity::update(float deltaTime)
{
	// TODO
	// sf::Vector2f toNormalize = getPosition() - m_target.getPosition();
	// float vectorLength = sqrt((toNormalize.x * toNormalize.x) + (toNormalize.y * toNormalize.y));
	// sf::Vector2f normalizedVector(toNormalize.x / vectorLength, toNormalize.y / vectorLength);

	// sf::Vector2f desired_velocity = (getPosition() - m_target.getPosition()) * (0.1f * deltaTime);
	// sf::Vector2f desired_velocity = normalizedVector * (0.1f * deltaTime);
	// sf::Vector2f steering = desired_velocity - velocity;
	// sf::Vector2f pos = getPosition() + steering;
	// setPosition(getPosition() + m_velocity);
	m_sprite.move(m_velocity);

	// We must also move the associated InfoPanel
	m_infoPanel.setPanelPosition(m_infoPanel.getPanelPosition() + m_velocity);
	// Update the text in the InfoPanel
	std::ostringstream entityInfoSS;
	entityInfoSS << "State: " << getState()->getStateName() << "\nHealth: " << m_health << "\nPosX: " << getPosition().x << "\nPosY: " << getPosition().y << "\nVelocityX: " << m_velocity.x << "\nVelocityY: " << m_velocity.y;
	m_infoPanel.setTextString(entityInfoSS.str());

	m_health--;
	m_state->update();
	if (m_health <= 0 && !m_dead)
	{
		setDead(true);
		// TODO Could be a part of setDead()
		setState(new DeadEntityState());
	}
}

void GameAIDemos::LiveEntity::draw()
{
	// TODO
}

void GameAIDemos::LiveEntity::setHealth(int health)
{
	m_health = health;
}

int GameAIDemos::LiveEntity::getHealth()
{
	return m_health;
}

void GameAIDemos::LiveEntity::setSpeed(float speed)
{
	m_logger.log("DEBUG", "Setting live entity speed.");
	m_speed = speed;
}

float GameAIDemos::LiveEntity::getSpeed()
{
	return m_speed;
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

sf::Vector2f GameAIDemos::LiveEntity::getVelocity()
{
	return m_velocity;
}

void GameAIDemos::LiveEntity::setVelocity(sf::Vector2f velocity)
{
	m_logger.log("DEBUG", "Setting entity velocity");
	m_velocity = velocity;
}

sf::Vector2f GameAIDemos::LiveEntity::getDirection()
{
	return m_direction;
}

void GameAIDemos::LiveEntity::setDirection(sf::Vector2f direction)
{
	m_direction = direction;
}
