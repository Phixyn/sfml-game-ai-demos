#ifndef GAME_H
#define GAME_H

#include "GameWindow.hpp"
#include "Scene.hpp"
#include <queue>

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
			/// <summary>
			/// Initializes the GameWindow instance and member variables.
			/// </summary>
			///
			/// <param name="WIDTH"> The width of the game window. </param>
			/// <param name="HEIGHT"> The height of the game window. </param>
			/// <param name="TITLE"> A title for the game window. </param>
			/// <param name="DEBUG">
			/// A boolean specifying if the game is to be run in debug mode.
			/// Defaults to true.
			/// </param>
			/// <seealso cref="GameWindow" />
			Game(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE, const bool DEBUG = true);

			/// <summary>
			/// Performs the game's main loop.
			/// </summary>
			void mainLoop();
			/// <summary>
			/// Adds a new scene to the game.
			/// </summary>
			///
			/// <param name="scene"> A unique pointer to a Scene. </param>
			/// <seealso cref="Scene" />
			void addScene(std::unique_ptr<Scene> scene);
			/// <summary>
			/// Removes a scene from the game.
			/// </summary>
			///
			/// <seealso cref="Scene" />
			void removeScene();
			/// <summary>
			/// Changes the current scene in the game.
			/// </summary>
			///
			/// <param name="scene"> A unique pointer to a Scene. </param>
			/// <seealso cref="Scene" />
			void changeScene(std::unique_ptr<Scene> scene);

			/// <summary>
			/// <see cref="GameWindow">GameWindow</see> instance for the game.
			/// </summary>
			GameWindow m_gameWindow;
		private:
			/// <summary>
			/// The delta time for the game's update frequency rate.
			/// </summary>
			float m_deltaTime;
			/// <summary>
			/// Boolean specifying if the game should run in debug mode.
			/// </summary>
			bool m_debugMode;
			/// <summary>
			/// Instance of SFML Clock used to measure time. Used to get
			/// a <see cref="m_deltaTime">delta time</see>.
			/// </summary>
			sf::Clock m_clock;
			/// <summary>
			/// Queue of unique pointers to <see cref="Scene">Scene</see>
			/// instances.
			/// </summary>
			std::queue<std::unique_ptr<Scene>> m_sceneQueue;
			/// <summary>
			/// Instance of <see cref="Logger">Logger</see> for logging.
			/// </summary>
			Logger m_logger;
	};
}

#endif
