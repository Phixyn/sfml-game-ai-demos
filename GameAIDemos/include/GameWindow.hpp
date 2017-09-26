#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <memory>
#include <SFML/Graphics.hpp>

namespace GameAIDemos
{
	class GameWindow
	{
		public:
			GameWindow(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE, bool showDebugPane);

		private:
			unsigned int m_WIDTH;
			unsigned int m_HEIGHT;
			std::string m_TITLE;

			bool m_showDebugPane;

			std::unique_ptr<sf::RenderWindow> m_window;
	};
}

#endif
