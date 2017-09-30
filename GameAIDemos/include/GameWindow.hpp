#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include "Logger.hpp"
#include <memory>
#include <SFML/Graphics.hpp>

namespace GameAIDemos
{
	/// <summary>
	/// Class used to create and manage game windows.
	/// </summary>
	class GameWindow
	{
		public:
			/// <summary>
			/// Default class constructor. Initializes all member variables
			/// and creates a new instance of SFML's RenderWindow.
			/// </summary>
			///
			/// <param name="WIDTH"> The width of the window. </param>
			/// <param name="HEIGHT"> The height of the window. </param>
			/// <param name="TITLE"> A title for the window. </param>
			/// <param name="SHOW_DEBUG_PANE"> A boolean specifying whether the
			/// debug pane should be displayed. Defaults to true. </param>
			GameWindow(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE, const bool SHOW_DEBUG_PANE = true);

			/// <summary>
			/// Clears the window by calling the clear method on the SFML
			/// RenderWindow instance.
			/// </summary>
			void clear();

			/// <summary>
			/// Resets the view (m_view) inside the window and calls the
			/// display method of the SFML RenderWindow to render the
			/// window.
			/// </summary>
			void render();

			/// <summary>
			/// Draws a SFML Drawable object on the window.
			/// </summary>
			///
			/// <param name="drawable">
			/// Reference to the SFML Drawable instance to be drawn on the
			/// window.
			/// </param>
			void draw(const sf::Drawable &drawable);

			/// <summary>
			/// Polls the SFML Window for events received in the window, and
			/// handles them appropriately.
			/// </summary>
			void handleEvents();

			/// <returns>
			/// A boolean indicating if the window is open.
			/// </returns>
			bool isOpen();

			/// <returns>
			/// A boolean indicating if the window has focus.
			/// </returns>
			bool hasFocus();

			/// <summary>
			/// SFML View instance for the game window.
			/// This could be moved to the game class in the future.
			/// </summary>
			sf::View m_view;
		private:
			/// <summary> Width of the game window. </summary>
			unsigned int m_width;
			/// <summary> Height of the game window. </summary>
			unsigned int m_height;
			/// <summary> Title of the game window seen in titlebar. </summary>
			std::string m_title;

			/// <summary>
			/// Boolean specifying if the debug pane should be displayed in the
			/// window. Defaults to true in the constructor.
			/// </summary>
			bool m_showDebugPane;
			/// <summary>
			/// Boolean specifying if the window has focus.
			/// This member variable is set in handleEvents() method.
			/// </summary>
			bool m_hasFocus;
			/// <summary>
			/// Unique pointer to SFML RenderWindow instance.
			/// </summary>
			std::unique_ptr<sf::RenderWindow> m_window;
			/// <summary>
			/// Instance of <see cref="Logger">Logger</see> for logging.
			/// </summary>
			Logger m_logger;
	};
}

#endif
