#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <memory>
#include <SFML/Graphics.hpp>

namespace GameAIDemos
{
	class GameWindow
	{
		public:
			GameWindow(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE);
			GameWindow(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE, bool showDebugPane);

			/// <summary> Clears the window by calling the clear method on the
			/// SFML Window instance. </summary>
			void clear();

			/// <summary> Calls the display method of the SFML Window to render
			/// the window. TODO: Expand this. </summary>
			void render();

			/// <summary> Draws a SFML Drawable object on the
			/// window. </summary>
			///
			/// <param name="drawable">
			/// Reference to the SFML Drawable instance to be drawn on the
			/// window.
			/// </param>
			void draw(const sf::Drawable &drawable);

			/// <summary> Handles SFML events received in the
			/// window. </summary>
			void handleEvents();

			/// <returns> A boolean indicating if the window is
			/// open. </returns>
			bool isOpen();

			/// <returns> A boolean indicating if the window has
			/// focus. </returns>
			bool hasFocus();

			// View for the game, this could be moved to the game class in the future
			sf::View m_view;
		private:
			unsigned int m_WIDTH;
			unsigned int m_HEIGHT;
			std::string m_TITLE;

			bool m_showDebugPane;
			/// <summary> Boolean specifying if the window has focus.
			/// This member variable is set in handleEvents()
			/// method. </summary>
			bool m_hasFocus;

			std::unique_ptr<sf::RenderWindow> m_window;
	};
}

#endif
