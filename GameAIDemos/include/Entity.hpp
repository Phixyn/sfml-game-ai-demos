#ifndef ENTITY_H
#define ENTITY_H

#include "Logger.hpp"
#include <SFML/Graphics.hpp>

namespace GameAIDemos
{
	/// <summary>
	/// Class for game entities such as items, NPCs, tiles and the player
	/// character.
	/// </summary>
	class Entity
	{
		public:
			/// <summary>
			/// Default constructor.
			/// </summary>
			///
			/// <param name="position">
			/// A SFML Vector2f containing the entity's position on the
			/// game scene.
			/// </param>
			Entity(sf::Vector2f position);

			/// <summary>
			/// Pure virtual method to handle events of the entity.
			/// </summary>
			virtual void handleEvents() = 0;

			/// <summary>
			/// Pure virtual method to update the entity.
			/// </summary>
			///
			/// <param name="deltaTime">
			/// The delta time for the update frequency rate.
			/// </param>
			virtual void update(float deltaTime) = 0;

			/// <summary>
			/// Pure virtual method for drawing the entity.
			/// </summary>
			virtual void draw() = 0;

			/// <summary>
			/// Sets the texture for the entity.
			/// </summary>
			///
			/// <param name="texture">
			/// A pointer to a SFML Texture object required by SFML's
			/// setTexture method.
			/// </param>
			void setTexture(sf::Texture *texture);

			/// <summary>
			/// Returns a new instance of <see cref="Collision">Collision</see>
			/// for this entity, which can be used to handle and solve
			/// collisions between this entity and other entities in the game.
			/// </summary>
			///
			/// <returns>
			/// A new instance of <see cref="Collision">Collision</see> with
			/// the entity's rectangle.
			/// </returns>
			// Collision getCollision();

			/// <summary>
			/// Width of the entity's rectangle.
			/// </summary>
			float m_rectWidth;
			/// <summary>
			/// Height of the entity's rectangle.
			/// </summary>
			float m_rectHeight;
			/// <summary>
			/// SFML RectangleShape instance for the entity's rectangle.
			/// </summary>
			sf::RectangleShape m_rect;
			// Collision m_collision; // TODO: make this private or protected?
		protected:
			sf::Vector2f m_position;
			/// <summary>
			/// Instance of <see cref="Logger">Logger</see> for logging.
			/// </summary>
			Logger m_logger;
	};
}

#endif
