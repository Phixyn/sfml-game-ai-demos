#include "../include/Entity.hpp"

/// <summary>
/// Initilizes the entity's <see cref="Collision">Collision</see> instance.
/// </summary>
GameAIDemos::Entity::Entity(sf::Vector2f position) :
	m_position(position)
//	, m_collision(m_rect)
{

}

/// <summary>
/// Calls the setTexture method of this entity's SFML RectangleShape instance
/// to give it a texture.
/// </summary>
void GameAIDemos::Entity::setTexture(sf::Texture *texture)
{
	m_rect.setTexture(texture);
}

void GameAIDemos::Entity::setColor(sf::Color &color)
{
	m_rect.setFillColor(color);
}

void GameAIDemos::Entity::setPosition(sf::Vector2f &position)
{
	m_rect.setPosition(position);
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
	return m_position;
}

/* TODO: Not yet implemented
GameAIDemos::Collision GameAIDemos::Entity::getCollision()
{
	return GameAIDemos::Collision(m_rect);
}
*/
