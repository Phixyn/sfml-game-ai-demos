#ifndef SCENE_H
#define SCENE_H

#include "Logger.hpp"
#include <SFML/Graphics.hpp>

namespace GameAIDemos
{
	// Forward declaration for the Game class.
	class Game;
	/// <summary>
	/// A class for scenes and scene management. Scenes can be anything
	/// from levels to main menu screens.
	/// </summary>
	class Scene
	{
		public:
			/// <summary>
			/// Default constructor.
			/// </summary>
			///
			/// <param name="game">
			/// A pointer to an instance of the <see cref="Game">Game</see>
			/// class.
			/// </param>
			Scene(Game &game);

			/// <summary>
			/// Pure virtual method to handle events in the scene.
			/// </summary>
			///
			/// <param name="sfEvent">
			/// A SFML event (e.g. generated user input) instance.
			/// </param>
			virtual void handleEvents(sf::Event sfEvent) = 0;

			/// <summary>
			/// Pure virtual method to update the scene.
			/// </summary>
			///
			/// <param name="deltaTime">
			/// The delta time for the update frequency rate.
			/// </param>
			virtual void update(float deltaTime) = 0;

			/// <summary>
			/// Pure virtual method for drawing the scene.
			/// </summary>
			virtual void draw() = 0;
		protected:
			/// <summary>
			/// Pointer to an instance of the <see cref="Game">Game</see>
			/// class.
			/// </summary>
			Game *m_game_ptr;
			/// <summary>
			/// Instance of <see cref="Logger">Logger</see> for logging.
			/// </summary>
			Logger m_logger;
	};
}

#endif
