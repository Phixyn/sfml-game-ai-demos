#ifndef INFO_PANEL_H
#define INFO_PANEL_H

#include "Logger.hpp"
#include <SFML/Graphics.hpp>

namespace GameAIDemos
{
	/// <summary>
	/// TODO
	/// </summary>
	class InfoPanel
	{
		public:
			InfoPanel();
			~InfoPanel() { }

			sf::Text getSFText();
			sf::RectangleShape getRect();
			std::string getTextString();

			void setTextString(std::string textString);
			void setPanelPosition(sf::Vector2f position);
		private:
			std::string m_panelTextString;
			sf::Vector2f m_panelPosition;
			sf::Vector2f m_panelTextPosition;
			sf::Font m_panelFont;
			sf::Text m_panelText;
			sf::RectangleShape m_panelRect;
			Logger m_logger;
	};
}

#endif