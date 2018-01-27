// Preprocessor definition to allow the use of default
// defines from math.h for M_PI
#define _USE_MATH_DEFINES
#include <math.h>
#include "../include/PlayerEntity.hpp"

GameAIDemos::PlayerEntity::PlayerEntity(int health, sf::Vector2f size, sf::Vector2f position) :
	LiveEntity(health, size, position)
{
	setTexture(ENTITY_TEXTURE);
	// Set rotation origin to be the center point of the sprite
	m_sprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
	// Set rotation so player is pointing upwards
	m_sprite.setRotation(-90.0f);
}

GameAIDemos::PlayerEntity::PlayerEntity(int health, sf::Vector2f size, sf::Vector2f position, float speed) :
	LiveEntity(health, size, position, speed)
{
	setTexture(ENTITY_TEXTURE);
	m_sprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
	m_sprite.setRotation(-90.0f);
}

void GameAIDemos::PlayerEntity::handleEvents(sf::Event sfEvent)
{
	if (sfEvent.type == sf::Event::KeyPressed)
	{
		float angle = m_sprite.getRotation();
		switch (sfEvent.key.code)
		{
			case sf::Keyboard::W:
				setVelocity(sf::Vector2f((float)(cos(angle * M_PI / 180.0f)), (float)(sin(angle * M_PI / 180.0f))));
				break;
			case sf::Keyboard::A:
				m_sprite.rotate(-5.0f);
				setVelocity(sf::Vector2f((float)(cos(angle * M_PI / 180.0f)), (float)(sin(angle * M_PI / 180.0f))));
				break;
			case sf::Keyboard::S:
				setVelocity(sf::Vector2f(0.0f, 0.0f));
				break;
			case sf::Keyboard::D:
				m_sprite.rotate(5.0f);
				setVelocity(sf::Vector2f((float)(cos(angle * M_PI / 180.0f)), (float)(sin(angle * M_PI / 180.0f))));
				break;
			default:
				break;
		}
	}
}

void GameAIDemos::PlayerEntity::update(float deltaTime)
{
	m_state->update();
	m_sprite.move(m_velocity);

	// We must also move the associated InfoPanel
	m_infoPanel.setPanelPosition(m_infoPanel.getPanelPosition() + m_velocity);
	// Update the text in the InfoPanel
	std::ostringstream entityInfoSS;
	entityInfoSS << "State: " << getState()->getStateName() << "\nHealth: " << m_health << "\nPosX: " << getPosition().x << "\nPosY: " << getPosition().y << "\nVelocityX: " << m_velocity.x << "\nVelocityY: " << m_velocity.y;
	m_infoPanel.setTextString(entityInfoSS.str());
}

void GameAIDemos::PlayerEntity::draw()
{
	// TODO
}
