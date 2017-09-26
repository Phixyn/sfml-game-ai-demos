#include "../include/GameWindow.hpp"

GameAIDemos::GameWindow::GameWindow(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE, bool showDebugPane)
{
	m_WIDTH = WIDTH;
	m_HEIGHT = HEIGHT;
	m_TITLE = TITLE;
	m_showDebugPane = showDebugPane;

	// m_logger.log("DEBUG", "Creating RenderWindow object.");
}