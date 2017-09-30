#include "../include/Game.hpp"

GameAIDemos::Game::Game(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE, const bool DEBUG) :
	m_debugMode(DEBUG), m_gameWindow(WIDTH, HEIGHT, TITLE, DEBUG)
{
	m_logger.log("INFO", "Initializing game.");
}

/// <summary> (TODO: list the steps). </summary>
void GameAIDemos::Game::mainLoop()
{
	m_logger.log("DEBUG", "Entering main loop.");
	// TODO temporary
	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color::Red);

	while (m_gameWindow.isOpen())
	{
		// (Re)start the clock and get the time elapsed since clock started,
		// as seconds
		m_deltaTime = m_clock.restart().asSeconds();
		// Limit framerate to 60
		if (m_deltaTime > 1.0f / 60.0f)
			m_deltaTime = 1.0f / 60.0f;

		// Handle window events
		m_gameWindow.handleEvents();
		// Clear game window
		m_gameWindow.clear();
		// Only handle events and update if we have focus on our window
		if (m_gameWindow.hasFocus())
		{
			// TODO
		}
		// TODO temporary
		m_gameWindow.draw(shape);
		// Render window
		m_gameWindow.render();
	}
	m_logger.log("DEBUG", "Exited main loop.");
}
