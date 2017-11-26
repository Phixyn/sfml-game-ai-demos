#include "../include/Entity.hpp"

/// <summary>
/// Initilizes the entity's <see cref="Collision">Collision</see> instance.
/// </summary>
GameAIDemos::Entity::Entity(sf::Vector2f size)
//	, m_collision(m_rect)
{
	m_rectWidth = size.x;
	m_rectHeight = size.y;
	m_logger.log("DEBUG", "Creating a new entity.");
	m_rect = sf::RectangleShape(sf::Vector2f(m_rectWidth, m_rectHeight));
}

GameAIDemos::Entity::Entity(sf::Vector2f size, sf::Vector2f position) :
	Entity(size)
{
	m_position = position;
	// TODO Rect no longer needed?
	m_rect.setPosition(m_position);
	m_sprite.setPosition(m_position);
	m_infoPanel.setPanelPosition(m_position - sf::Vector2f(0, ((m_rectHeight / 2.0f) + m_infoPanel.getPanelSize().y)));
}

GameAIDemos::Entity::Entity(sf::Vector2f size, std::string textureFilePath) :
	Entity(size)
{
	setTexture(textureFilePath);
}

GameAIDemos::Entity::Entity(sf::Vector2f size, sf::Vector2f position, std::string textureFilePath) :
	Entity(size, position)
{
	setTexture(textureFilePath);
}

/// <summary>
/// Calls the setTexture method of this entity's SFML Sprite instance
/// to give it a texture.
/// </summary>
void GameAIDemos::Entity::setTexture(sf::Texture texture)
{
	m_logger.log("DEBUG", "Applying texture to entity.");
	m_texture = texture;
	m_texture.setSmooth(true);
	m_sprite.setTexture(texture);
}

void GameAIDemos::Entity::setTexture(std::string textureFilePath)
{
	if (!m_texture.loadFromFile(textureFilePath))
	{
		m_logger.log("ERROR", "Could not load texture image: " + textureFilePath);
		return;
	}

	m_logger.log("INFO", "Loaded entity texture from image file: " + textureFilePath);
	m_logger.log("DEBUG", "Applying texture to entity.");
	m_texture.setSmooth(true);
	m_sprite.setTexture(m_texture);
}

void GameAIDemos::Entity::setColor(sf::Color color)
{
	m_rect.setFillColor(color);
}

void GameAIDemos::Entity::setSpriteColor(sf::Color color)
{
	m_sprite.setColor(color);
}

void GameAIDemos::Entity::setPosition(sf::Vector2f &position)
{
	m_sprite.setPosition(position);
}

void GameAIDemos::Entity::toggleInfoPanel()
{
	m_displayInfoPanel = !m_displayInfoPanel;
}

float GameAIDemos::Entity::getRectWidth()
{
	return m_rectWidth;
}

float GameAIDemos::Entity::getRectHeight()
{
	return m_rectHeight;
}

sf::Vector2f GameAIDemos::Entity::getPosition()
{
	return m_sprite.getPosition();
}

sf::RectangleShape GameAIDemos::Entity::getRect()
{
	return m_rect;
}

sf::Sprite GameAIDemos::Entity::getSprite()
{
	return m_sprite;
}

GameAIDemos::InfoPanel GameAIDemos::Entity::getInfoPanel()
{
	return m_infoPanel;
}

bool GameAIDemos::Entity::isInfoPanelEnabled()
{
	return m_displayInfoPanel;
}

/* TODO: Not yet implemented
GameAIDemos::Collision GameAIDemos::Entity::getCollision()
{
	return GameAIDemos::Collision(m_rect);
}
*/
