#include "../include/LevelScene.hpp"
#include "../include/Game.hpp"
#include <fstream>

GameAIDemos::LevelScene::LevelScene(Game &game, std::string backgroundImagePath) :
	Scene(game)
{
	m_logger.log("DEBUG", "Initializing level scene.");
	setBackgroundImage(backgroundImagePath);
}

void GameAIDemos::LevelScene::handleEvents()
{
	// TODO
}

/// <summary>
/// <para> Checks for collision between the scene's entities. </para>
/// <para> Calls the update methods for the entities. </para>
/// </summary>
void GameAIDemos::LevelScene::update(float deltaTime)
{
	// TODO
}

/// <summary>
/// <para> Draws the scene's entities into the game's window. </para>
/// <para> Accesses the game's window via the
/// <see cref="m_game_ptr">m_game_ptr</see> pointer member variable. </para>
/// </summary>
void GameAIDemos::LevelScene::draw()
{
	// TODO temporary placeholder shape
	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color::Red);
	m_game_ptr->m_gameWindow.draw(shape);

	// TODO
	// m_game_ptr->m_gameWindow.draw(m_backgroundSprite);

	// TODO: liveEntities
	/*
	for (LiveEntity* liveEntity : m_liveEntities)
	{
		m_game_ptr->m_gameWindow.drawRect(liveEntity->m_rect);
	}
	*/
}

/// <summary>
/// Attempts to load an image from a file and set it as background image for
/// the level scene. Sets the background sprite's local origin and texture
/// rect.
/// </summary>
void GameAIDemos::LevelScene::setBackgroundImage(std::string imageFilePath)
{
	if (!m_backgroundTexture.loadFromFile(imageFilePath))
	{
		m_logger.log("ERROR", "Could not load level background image: " + imageFilePath);
		return;
	}

	m_logger.log("INFO", "Loaded background image file: " + imageFilePath);
	m_logger.log("DEBUG", "Applying background image to level scene.");
	// TODO: Handle tileable backgrounds?
	// m_backgroundTexture.setRepeated(true);
	m_backgroundSprite.setTexture(m_backgroundTexture);
	// m_backgroundSprite.setOrigin(m_game_ptr->m_gameWindow.m_view.getCenter().x, m_game_ptr->m_gameWindow.m_view.getCenter().y / 2.0f);
	m_backgroundSprite.setOrigin(m_game_ptr->m_gameWindow.m_view.getCenter());
	m_backgroundSprite.setTextureRect(sf::IntRect(0, 0, m_game_ptr->m_gameWindow.m_view.getSize().x, m_game_ptr->m_gameWindow.m_view.getSize().y));
}