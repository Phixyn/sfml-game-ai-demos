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
	for (LiveEntity &liveEntity : m_liveEntities)
	{
		liveEntity.handleEvents();
	}
}

/// <summary>
/// <para> Checks for collision between the scene's entities. </para>
/// <para> Calls the update methods for the entities. </para>
/// </summary>
void GameAIDemos::LevelScene::update(float deltaTime)
{
	for (LiveEntity &liveEntity : m_liveEntities)
	{
		liveEntity.update(deltaTime);
	}
}

/// <summary>
/// <para> Draws the scene's entities into the game's window. </para>
/// <para> Accesses the game's window via the
/// <see cref="m_game_ptr">m_game_ptr</see> pointer member variable. </para>
/// </summary>
void GameAIDemos::LevelScene::draw()
{
	// TODO
	// m_game_ptr->m_gameWindow.draw(m_backgroundSprite);

	for (LiveEntity &liveEntity : m_liveEntities)
	{
		m_game_ptr->m_gameWindow.draw(liveEntity.m_rect);
	}
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

void GameAIDemos::LevelScene::spawnLiveEntity(LiveEntity entity)
{
	m_liveEntities.push_back(entity);
}

void GameAIDemos::LevelScene::spawnLiveEntity(int health, sf::Vector2f size, sf::Vector2f position)
{
	m_liveEntities.push_back(LiveEntity(health, size, position));
}

void GameAIDemos::LevelScene::spawnLiveEntity(int health, sf::Vector2f size, sf::Vector2f position, float speed)
{
	m_liveEntities.push_back(LiveEntity(health, size, position, speed));
}
