#include "../include/Game.hpp"

GameAIDemos::Game::Game(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE, const bool SHOW_DEBUG_PANE) :
	m_view(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 2.0f), sf::Vector2f((float)WIDTH, (float)HEIGHT)),
	m_width(WIDTH), m_height(HEIGHT), m_title(TITLE), m_showDebugPane(SHOW_DEBUG_PANE)
{
	m_logger.log("INFO", "Initializing game.");
	m_logger.log("DEBUG", "Creating RenderWindow instance.");
	m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Close);
	m_window->setFramerateLimit(60);
	m_window->requestFocus();
}

void GameAIDemos::Game::clear()
{
	m_window->clear();
}

void GameAIDemos::Game::render()
{
	// Reset the view
	m_window->setView(m_view);
	m_window->display();
}

void GameAIDemos::Game::draw(const sf::Drawable &drawable)
{
	m_window->draw(drawable);
}

void GameAIDemos::Game::handleEvents()
{
	sf::Event sfEvent;

	while (m_window->pollEvent(sfEvent))
	{
		// Handle window events first
		switch (sfEvent.type)
		{
		case sf::Event::Closed:
			m_logger.log("DEBUG", "Closing game window.");
			m_window->close();
			break;
		case sf::Event::LostFocus:
			m_hasFocus = false;
			break;
		case sf::Event::GainedFocus:
			m_hasFocus = true;
			break;
		default:
			// Handle scene events
			m_sceneQueue.front()->handleEvents(sfEvent);
			break;
		}
	}
}

bool GameAIDemos::Game::isOpen()
{
	return m_window->isOpen();
}

bool GameAIDemos::Game::hasFocus()
{
	return m_hasFocus;
}

/// <summary>
/// Handles user input, updates game state and renders the game scene.
/// </summary>
void GameAIDemos::Game::mainLoop()
{
	m_logger.log("DEBUG", "Entering main loop.");
	while (m_window->isOpen())
	{
		// (Re)start the clock and get the time elapsed since clock started,
		// as seconds
		m_deltaTime = m_clock.restart().asSeconds();
		// Limit framerate to 60
		if (m_deltaTime > 1.0f / 60.0f)
			m_deltaTime = 1.0f / 60.0f;

		// Handle window events
		handleEvents();
		// Clear game window
		clear();
		// Before we continue with the main loop, we should check if the
		// scene queue has items. Attempting to access an empty queue
		// could be bad.
		if (m_sceneQueue.empty())
		{
			m_logger.log("FATAL", "Game has no scenes. Unable to continue game main loop. Please add a scene to the game.");
			exit(1);
		}
		// Only handle events and update if we have focus on our window
		if (m_window->hasFocus())
		{
			// Handle scene events
			// m_sceneQueue.front()->handleEvents();
			// Update scene
			m_sceneQueue.front()->update(m_deltaTime);
		}
		// (Re)draw scene
		m_sceneQueue.front()->draw();
		// Render window
		render();
	}
	m_logger.log("DEBUG", "Exited main loop.");
}

/// <summary>
/// Adds a pointer to a <see cref="Scene">Scene</see> to the game's scene
/// pointer queue. std::move() is used as to not push a copy of the pointer,
/// but rather the pointer itself.
/// </summary>
void GameAIDemos::Game::addScene(std::unique_ptr<Scene> scene)
{
	m_logger.log("DEBUG", "Adding new scene to game.");
	m_sceneQueue.push(std::move(scene));
}

/// <summary>
/// Calls pop() on the <see cref="Scene">Scene</see> pointer queue.
/// </summary>
void GameAIDemos::Game::removeScene()
{
	if (!m_sceneQueue.empty())
	{
		m_logger.log("DEBUG", "Removing a scene from game.");
		m_sceneQueue.pop();
	}
	else
	{
		m_logger.log("DEBUG", "Could not remove scene from game: scene queue is empty.");
		return;
	}
}

/// <summary>
/// Changes to a new scene in the game by removing the top scene and adding
/// a new scene to the queue.
/// </summary>
void GameAIDemos::Game::changeScene(std::unique_ptr<Scene> scene)
{
	m_logger.log("DEBUG", "Changing game scene.");
	removeScene();
	addScene(std::move(scene));
}
