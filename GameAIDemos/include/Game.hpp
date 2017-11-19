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
			/// <param name="SHOW_DEBUG_PANE"> A boolean specifying whether the
			/// debug pane should be displayed. Defaults to true. </param>
			Game(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE, const bool SHOW_DEBUG_PANE = true);

			/// <summary>
			/// Clears the window by calling the clear method on the SFML
			/// RenderWindow instance.
			/// </summary>
			void clear();

			/// <summary>
			/// Resets the view (<see cref="m_view">m_view</see>) inside the
			/// window and calls the display method of the SFML RenderWindow
			/// to render the window.
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
			/// SFML View instance for the game window.
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
			/// Boolean specifying if the window has focus.
			/// This member variable is set in handleEvents() method.
			/// </summary>
			bool m_hasFocus;

			/// <summary>
			/// The delta time for the game's update frequency rate.
			/// </summary>
			float m_deltaTime;
			/// <summary>
			/// Boolean specifying if the debug pane should be displayed in the
			/// game window. Defaults to true in the constructor.
			/// </summary>
			bool m_showDebugPane;
			/// <summary>
			/// Instance of SFML Clock used to measure time. Used to get
			/// a <see cref="m_deltaTime">delta time</see>.
			/// </summary>
			sf::Clock m_clock;
			/// <summary>
			/// Unique pointer to SFML RenderWindow instance.
			/// </summary>
			std::unique_ptr<sf::RenderWindow> m_window;
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
