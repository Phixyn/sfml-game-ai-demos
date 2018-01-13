#include "../include/LevelScene.hpp"
#include "../include/Game.hpp"
#include <fstream>

GameAIDemos::LevelScene::LevelScene(Game &game, std::string backgroundImagePath) :
	Scene(game)
{
	m_logger.log("DEBUG", "Initializing level scene.");
	setBackgroundImage(backgroundImagePath);
}

void GameAIDemos::LevelScene::handleEvents(sf::Event sfEvent)
{
	// Handle events for live entities in this scene
	for (LiveEntity &liveEntity : m_liveEntities)
	{
		if (sfEvent.type == sf::Event::MouseButtonPressed &&
			sfEvent.mouseButton.button == sf::Mouse::Left)
		{
			// Get mouse position relative to the game window
			sf::Vector2i mouseClickPos = sf::Mouse::getPosition(*m_game_ptr->m_window);
			// Position of live entity's sprite
			sf::Vector2f liveEntityPos = liveEntity.getSprite().getPosition();

			// Check if mouse click was within the entity's sprite
			if (mouseClickPos.x > liveEntityPos.x
				&& mouseClickPos.x < liveEntityPos.x + liveEntity.getRectWidth()
				&& mouseClickPos.y > liveEntityPos.y
				&& mouseClickPos.y < liveEntityPos.y + liveEntity.getRectHeight())
			{
				m_logger.log("DEBUG", "Received mouse click on sprite.");
				std::ostringstream oss;
				oss << sf::Mouse::getPosition(*m_game_ptr->m_window).x << " " << sf::Mouse::getPosition(*m_game_ptr->m_window).y;
				m_logger.log("DEBUG", oss.str());
				// TODO we should handle the event in the entity instead of here?
				// TODO Let the entity know that there was a mouse click on it, and let it decide what to do with it
				// liveEntity.handleEvents(sfEvent);
				liveEntity.toggleInfoPanel();
				liveEntity.toggleSelected();
			}
		}
		else
		{
			// TODO we should handle the event in the entity instead of here?
			// TODO Let the entity know that there was a mouse click on it, and let it decide what to do with it
			liveEntity.handleEvents(sfEvent);
		}
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
	// m_game_ptr->draw(m_backgroundSprite);

	for (LiveEntity &liveEntity : m_liveEntities)
	{
		m_game_ptr->draw(liveEntity.getSprite());
		if (liveEntity.isInfoPanelEnabled())
		{
			m_game_ptr->draw(liveEntity.getInfoPanel().getRect());
			m_game_ptr->draw(liveEntity.getInfoPanel().getSFText());
		}
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
	// m_backgroundSprite.setOrigin(m_game_ptr->m_view.getCenter().x, m_game_ptr->m_view.getCenter().y / 2.0f);
	m_backgroundSprite.setOrigin(m_game_ptr->m_view.getCenter());
	m_backgroundSprite.setTextureRect(sf::IntRect(0, 0, m_game_ptr->m_view.getSize().x, m_game_ptr->m_view.getSize().y));
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
