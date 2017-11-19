#include "../include/InfoPanel.hpp"

GameAIDemos::InfoPanel::InfoPanel()
{
	m_panelPosition = sf::Vector2f(100.0f, 100.f);
	m_panelTextPosition = m_panelPosition + sf::Vector2f(15.0f, 15.0f);

	if (!m_panelFont.loadFromFile("assets/arial.ttf"))
	{
		m_logger.log("ERROR", "Could not load font from file: 'assets/arial.ttf'");
		return;
	}
	
	m_panelText.setFont(m_panelFont);
	m_panelText.setCharacterSize(15);
	m_panelText.setFillColor(sf::Color::White);
	m_panelText.setStyle(sf::Text::Bold);
	m_panelText.setPosition(m_panelTextPosition);
	m_panelText.setString("State: Idle\nHealth: 100");

	m_panelRect = sf::RectangleShape(sf::Vector2f(150, 125));
	m_panelRect.setFillColor(sf::Color::Transparent);
	m_panelRect.setOutlineColor(sf::Color::Red);
	m_panelRect.setOutlineThickness(2);
	m_panelRect.setPosition(m_panelPosition);
}

sf::Text GameAIDemos::InfoPanel::getSFText()
{
	return m_panelText;
}

sf::RectangleShape GameAIDemos::InfoPanel::getRect()
{
	return m_panelRect;
}

std::string GameAIDemos::InfoPanel::getTextString()
{
	return m_panelTextString;
}

void GameAIDemos::InfoPanel::setTextString(std::string textString)
{
	m_panelTextString = textString;
	m_panelText.setString(m_panelTextString);
}

void GameAIDemos::InfoPanel::setPanelPosition(sf::Vector2f position)
{
	m_panelPosition = position;
	m_panelRect.setPosition(m_panelPosition);
}
