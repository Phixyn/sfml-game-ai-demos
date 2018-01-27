#include "../include/AgentEntity.hpp"
#include "../include/Game.hpp"
#include "../include/LevelScene.hpp"
#include <fstream>

GameAIDemos::LevelScene::LevelScene(Game &game, PlayerEntity &player, std::string backgroundImagePath) :
	Scene(game), m_playerEntity(&player)
{
	m_logger.log("DEBUG", "Initializing level scene.");
	setBackgroundImage(backgroundImagePath);
}

void GameAIDemos::LevelScene::handleEvents(sf::Event sfEvent)
{
	// Handle keyboard events for shortcuts in level
	if (sfEvent.type == sf::Event::KeyPressed &&
		sfEvent.key.code == sf::Keyboard::V)
	{
		// Spawn an entity where the mouse cursor currently is
		// Get mouse cursor position in the window
		sf::Vector2i mousePos = sf::Mouse::getPosition(*m_game_ptr->m_window);
		// Spawn new entity and add to our live entities vector
		m_liveEntities.push_back(new GameAIDemos::AgentEntity(100,
			sf::Vector2f(32.0f, 32.0f),
			sf::Vector2f((float)mousePos.x, (float)mousePos.y),
			*m_playerEntity));
	}

	// Handle mouse click on player entity
	if (sfEvent.type == sf::Event::MouseButtonPressed &&
		sfEvent.mouseButton.button == sf::Mouse::Left)
	{
		// Get mouse position relative to the game window
		sf::Vector2i mouseClickPos = sf::Mouse::getPosition(*m_game_ptr->m_window);

		// Check if mouse click was within the player's sprite
		if (m_playerEntity->getSprite().getGlobalBounds().contains(mouseClickPos.x, mouseClickPos.y))
		{
			m_logger.log("DEBUG", "Received mouse click on sprite.");
			std::ostringstream oss;
			oss << sf::Mouse::getPosition(*m_game_ptr->m_window).x << " " << sf::Mouse::getPosition(*m_game_ptr->m_window).y;
			m_logger.log("DEBUG", oss.str());
			// TODO we should handle the event in the entity instead of here?
			// TODO Let the entity know that there was a mouse click on it, and let it decide what to do with it
			// m_playerEntity.handleEvents(sfEvent);
			m_playerEntity->toggleInfoPanel();
			m_playerEntity->toggleSelected();
		}
	}
	else
	{
		// TODO we should handle the event in the entity instead of here?
		// TODO Let the entity know that there was a mouse click on it, and let it decide what to do with it
		m_playerEntity->handleEvents(sfEvent);
	}

	// Handle events for live entities in this scene
	for (auto &liveEntity : m_liveEntities)
	{
		if (sfEvent.type == sf::Event::MouseButtonPressed &&
			sfEvent.mouseButton.button == sf::Mouse::Left)
		{
			// Get mouse position relative to the game window
			sf::Vector2i mouseClickPos = sf::Mouse::getPosition(*m_game_ptr->m_window);

			// Check if mouse click was within the entity's sprite
			if (liveEntity->getSprite().getGlobalBounds().contains(mouseClickPos.x, mouseClickPos.y))
			{
				m_logger.log("DEBUG", "Received mouse click on sprite.");
				std::ostringstream oss;
				oss << sf::Mouse::getPosition(*m_game_ptr->m_window).x << " " << sf::Mouse::getPosition(*m_game_ptr->m_window).y;
				m_logger.log("DEBUG", oss.str());
				// TODO we should handle the event in the entity instead of here?
				// TODO Let the entity know that there was a mouse click on it, and let it decide what to do with it
				// liveEntity.handleEvents(sfEvent);
				liveEntity->toggleInfoPanel();
				liveEntity->toggleSelected();
			}
		}
		else
		{
			// TODO we should handle the event in the entity instead of here?
			// TODO Let the entity know that there was a mouse click on it, and let it decide what to do with it
			liveEntity->handleEvents(sfEvent);
		}
	}
}

/// <summary>
/// <para> Checks for collision between the scene's entities. </para>
/// <para> Calls the update methods for the entities. </para>
/// </summary>
void GameAIDemos::LevelScene::update(float deltaTime)
{
	// TODO: Collision detection here?

	// Update player entity
	m_playerEntity->update(deltaTime);

	// Player collision detection with window bounds
	// If player is going out of window bounds, clip them to bounds
	// TODO improve this section and code duplication
	sf::Vector2f playerPos = m_playerEntity->getPosition();
	float playerWidth = m_playerEntity->getRectWidth();
	float playerHeight = m_playerEntity->getRectHeight();
	sf::Vector2f viewSize = m_game_ptr->m_view.getSize();

	if (playerPos.x >= viewSize.x - (playerWidth / 2))
	{
		m_playerEntity->setPosition(sf::Vector2f(viewSize.x - (playerWidth / 2), playerPos.y));
		m_playerEntity->setVelocity(sf::Vector2f(0.0f, 0.0f));
	}

	if (playerPos.x <= playerWidth / 2)
	{
		m_playerEntity->setPosition(sf::Vector2f(playerWidth / 2, playerPos.y));
		m_playerEntity->setVelocity(sf::Vector2f(0.0f, 0.0f));
	}

	if (playerPos.y >= viewSize.y - (playerHeight / 2))
	{
		m_playerEntity->setPosition(sf::Vector2f(playerPos.x, viewSize.y - (playerHeight / 2)));
		m_playerEntity->setVelocity(sf::Vector2f(0.0f, 0.0f));
	}

	if (playerPos.y <= playerHeight / 2)
	{
		m_playerEntity->setPosition(sf::Vector2f(playerPos.x, playerHeight / 2));
		m_playerEntity->setVelocity(sf::Vector2f(0.0f, 0.0f));
	}

	// Update all live entities in the scene
	for (auto &liveEntity : m_liveEntities)
	{
		liveEntity->update(deltaTime);
		// TODO LiveEntity collision detection and handling
	}
}

/// <summary>
/// <para> Draws the scene's entities into the game's window. </para>
/// <para> Accesses the game's window via the
/// <see cref="m_game_ptr">m_game_ptr</see> pointer member variable. </para>
/// </summary>
void GameAIDemos::LevelScene::draw()
{
	// Draw level scene background image
	m_game_ptr->draw(m_backgroundSprite);

	// Draw player and its info panel, if enabled
	m_game_ptr->draw(m_playerEntity->getSprite());
	if (m_playerEntity->isInfoPanelEnabled())
	{
		m_game_ptr->draw(m_playerEntity->getInfoPanel().getRect());
		m_game_ptr->draw(m_playerEntity->getInfoPanel().getSFText());
	}

	// Draw all live entities in the scene
	for (auto &liveEntity : m_liveEntities)
	{
		m_game_ptr->draw(liveEntity->getSprite());
		if (liveEntity->isInfoPanelEnabled())
		{
			m_game_ptr->draw(liveEntity->getInfoPanel().getRect());
			m_game_ptr->draw(liveEntity->getInfoPanel().getSFText());
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
	// m_backgroundSprite.setOrigin(m_game_ptr->m_view.getCenter());
	// m_backgroundSprite.setTextureRect(sf::IntRect(0, 0, m_game_ptr->m_view.getSize().x, m_game_ptr->m_view.getSize().y));
}

void GameAIDemos::LevelScene::spawnLiveEntity(LiveEntity &entity)
{
	m_liveEntities.push_back(&entity);
}

void GameAIDemos::LevelScene::spawnLiveEntity(int health, sf::Vector2f size, sf::Vector2f position)
{
	m_liveEntities.push_back(&LiveEntity(health, size, position));
}

void GameAIDemos::LevelScene::spawnLiveEntity(int health, sf::Vector2f size, sf::Vector2f position, float speed)
{
	m_liveEntities.push_back(&LiveEntity(health, size, position, speed));
}
