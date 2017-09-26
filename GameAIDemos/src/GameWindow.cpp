#include "../include/GameWindow.hpp"

GameAIDemos::GameWindow::GameWindow(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE, bool showDebugPane)
{
	m_WIDTH = WIDTH;
	m_HEIGHT = HEIGHT;
	m_TITLE = TITLE;
	m_showDebugPane = showDebugPane;

	// m_logger.log("DEBUG", "Creating RenderWindow object.");
	m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Close);
	m_window->requestFocus();
}

void GameAIDemos::GameWindow::clear()
{
	m_window->clear();
}

void GameAIDemos::GameWindow::render()
{
	// Reset the view
	m_window->setView(m_view);
	m_window->display();
}