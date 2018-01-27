#ifndef INFO_PANEL_H
#define INFO_PANEL_H

#include "Logger.hpp"
#include <sstream>
#include <SFML/Graphics.hpp>

namespace GameAIDemos
{
	/// <summary>
	/// A class for information panel UI elements. An info panel element in
	/// the UI is a simple rectangle with text displayed inside it. This
	/// can be used to display game information, tooltips, HUD elements
	/// and more. It may also be attached to entities to display their
	/// information, such as health and current state.
	/// </summary>
	class InfoPanel
	{
		public:
			/// <summary>
			/// Default constructor. Initializes and sets up the SFML Font,
			/// Text and RectangleShape instances for this panel. Sets the
			/// panel's position, as well as the text's position, and gives
			/// the panel a default text string.
			/// </summary>
			InfoPanel();
			/// <summary>
			/// Default empty destructor.
			/// </summary>
			~InfoPanel() { }

			/// <summary>
			/// Gets the SFML Text instance used for this panel.
			/// </summary>
			///
			/// <returns>
			/// A SFML Text instance used for this panel.
			/// </returns>
			sf::Text getSFText();
			/// <summary>
			/// Gets the SFML RectangleShape instance of the panel.
			/// </summary>
			///
			/// <returns>
			/// A SFML RectangleShape instance used for this panel.
			/// </returns>
			sf::RectangleShape getRect();
			/// <summary>
			/// Gets the size of the panel.
			/// </summary>
			///
			/// <returns>
			/// A SFML Vector containing the width and height of the panel.
			/// </returns>
			sf::Vector2f getPanelSize();
			/// <summary>
			/// Gets the position of the panel.
			/// </summary>
			///
			/// <returns>
			/// A SFML Vector containing the position of the panel in the
			/// game window.
			/// </returns>
			sf::Vector2f getPanelPosition();
			/// <summary>
			/// Gets the text being currently displayed in the panel.
			/// </summary>
			///
			/// <returns>
			/// The current string displayed in the panel.
			/// </returns>
			std::string getTextString();

			/// <summary>
			/// Sets the text displayed inside this panel.
			/// </summary>
			///
			/// <param name="textString">
			/// A string containing the new text for this panel.
			/// </param>
			void setTextString(std::string textString);
			/// <summary>
			/// Sets this panel's position in the game window.
			/// </summary>
			///
			/// <param name="position">
			/// A SFML Vector containing the new position for this panel in the
			/// game window.
			/// </param>
			void setPanelPosition(sf::Vector2f& position);
		private:
			/// <summary>
			/// A string containing the text that will be displayed in this
			/// panel.
			/// </summary>
			std::string m_panelTextString;
			/// <summary>
			/// The position of this panel in the game window.
			/// </summary>
			sf::Vector2f m_panelPosition;
			/// <summary>
			/// An offset in relation to the text's position within the panel's
			/// rectangle. Effectively acts as a "padding" for the text inside
			/// the rectangle.
			/// </summary>
			sf::Vector2f m_panelTextOffset;
			/// <summary>
			/// The position of the text inside the panel.
			/// </summary>
			sf::Vector2f m_panelTextPosition;
			/// <summary>
			/// A SFML Font object for the panel's text font.
			/// </summary>
			sf::Font m_panelFont;
			/// <summary>
			/// A SFML Text object for the panel's text.
			/// </summary>
			sf::Text m_panelText;
			/// <summary>
			/// A SFML RectangleShape object for the panel's outline and
			/// background.
			/// </summary>
			sf::RectangleShape m_panelRect;

			/// <summary>
			/// Instance of <see cref="Logger">Logger</see> for logging.
			/// </summary>
			Logger m_logger;
	};
}

#endif
