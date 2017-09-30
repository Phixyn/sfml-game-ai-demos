#include "../include/GameWindow.hpp"

GameAIDemos::GameWindow::GameWindow(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE, const bool SHOW_DEBUG_PANE) :
	m_view(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 2.0f), sf::Vector2f((float)WIDTH, (float)HEIGHT)),
	m_width(WIDTH), m_height(HEIGHT), m_title(TITLE), m_showDebugPane(SHOW_DEBUG_PANE)
{
	m_logger.log("DEBUG", "Creating RenderWindow object.");
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

void GameAIDemos::GameWindow::draw(const sf::Drawable &drawable)
{
	m_window->draw(drawable);
}

void GameAIDemos::GameWindow::handleEvents()
{
	sf::Event sfEvent;

	while (m_window->pollEvent(sfEvent))
	{
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
		}
	}
}

bool GameAIDemos::GameWindow::isOpen()
{
	return m_window->isOpen();
}

bool GameAIDemos::GameWindow::hasFocus()
{
	return m_hasFocus;
}