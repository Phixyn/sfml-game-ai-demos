#include "../include/AgentEntity.hpp"
#include "../include/FleeEntityState.hpp"
#include "../include/IdleEntityState.hpp"
#include "../include/SeekEntityState.hpp"

GameAIDemos::AgentEntity::AgentEntity(int health, sf::Vector2f size, sf::Vector2f position, PlayerEntity& player) :
	LiveEntity(health, size, position), m_playerPtr(&player)
{
	setTexture(ENTITY_TEXTURE);
	// Set rotation origin to be the center point of the sprite
	// TODO this is breaking the position of the info panels for agent entities
	// m_sprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
	setState(new IdleEntityState(this));
}

GameAIDemos::AgentEntity::AgentEntity(int health, sf::Vector2f size, sf::Vector2f position, float speed, PlayerEntity& player) :
	LiveEntity(health, size, position, speed), m_playerPtr(&player)
{
	setTexture(ENTITY_TEXTURE);
	// m_sprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
	setState(new IdleEntityState(this));
}

void GameAIDemos::AgentEntity::handleEvents(sf::Event sfEvent)
{
	if (sfEvent.type == sf::Event::KeyPressed && m_isSelected)
	{
		switch (sfEvent.key.code)
		{
			case sf::Keyboard::F:
				setState(new SeekEntityState(this, *m_playerPtr));
				break;
			case sf::Keyboard::E:
				setState(new FleeEntityState(this, *m_playerPtr));
				break;
			case sf::Keyboard::I:
				setState(new IdleEntityState(this));
				break;
			default:
				break;
		}
	}
}

void GameAIDemos::AgentEntity::update(float deltaTime)
{
	m_state->update();
	m_sprite.move(m_velocity);

	// We must also move the associated InfoPanel
	// TODO: might be better to do this as part of the state's update() method
	// (only the position part, not updating the text)
	m_infoPanel.setPanelPosition(m_infoPanel.getPanelPosition() + m_velocity);
	// Update the text in the InfoPanel
	std::ostringstream entityInfoSS;
	entityInfoSS << "State: " << getState()->getStateName() << "\nHealth: " << m_health << "\nPosX: " << getPosition().x << "\nPosY: " << getPosition().y << "\nVelocityX: " << m_velocity.x << "\nVelocityY: " << m_velocity.y;
	m_infoPanel.setTextString(entityInfoSS.str());
}

void GameAIDemos::AgentEntity::draw()
{
	// TODO
}
