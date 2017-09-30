#ifndef GAME_H
#define GAME_H

#include "GameWindow.hpp"

/// <summary>
/// Namespace for the game AI demos.
/// </summary>
namespace GameAIDemos
{
	/// <summary>
	/// Main game class used to initialize the game, create a game window
	/// and add scenes to it.
	/// </summary>
	class Game
	{
		public:
			/// <summary> Default constructor. </summary>
			///
			/// <param name="WIDTH"> The width of the game window. </param>
			/// <param name="HEIGHT"> The height of the game window. </param>
			/// <param name="TITLE"> A title for the game window. </param>
			/// <param name="DEBUG">
			/// A boolean specifying if the game is to be run in debug mode.
			/// Defaults to true.
			/// </param>
			Game(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE, const bool DEBUG = true);

			/// <summary> Handles the game's main loop. </summary>
			void mainLoop();

			/// <summary> Window instance for the game. </summary>
			GameWindow m_gameWindow;
		private:
			float m_deltaTime;
			bool m_debugMode;
		
			Logger m_logger;
	};
}

#endif