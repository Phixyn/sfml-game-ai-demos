#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H

#include "LiveEntity.hpp"

namespace GameAIDemos
{
	/// <summary>
	/// Subclass of <see cref="LiveEntity">LiveEntity</see> for the player
	/// character entity.
	/// </summary>
	class PlayerEntity : public LiveEntity
	{
		public:
			/// <summary>
			/// Default constructor taking parameters for the player's health,
			/// size and position.
			/// </summary>
			///
			/// <param name="health">
			/// The health points of the player entity.
			/// </param>
			/// <param name="size">
			/// A SFML Vector2f containing the player entity's size.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the player's position on the
			/// game scene.
			/// </param>
			PlayerEntity(int health, sf::Vector2f size, sf::Vector2f position);

			/// <summary>
			/// Overloaded constructor taking an additional parameter for the
			/// player's speed.
			/// </summary>
			///
			/// <param name="health">
			/// The health points of the player entity.
			/// </param>
			/// <param name="size">
			/// A SFML Vector2f containing the player entity's size.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the player's position on the
			/// game scene.
			/// </param>
			/// <param name="speed">
			/// The movement speed of the player entity.
			/// </param>
			PlayerEntity(int health, sf::Vector2f size, sf::Vector2f position, float speed);

			/// <summary>
			/// Handles events specific to the player entity.
			/// </summary>
			///
			/// <param name="sfEvent">
			/// A SFML event (e.g. generated user input) object.
			/// </param>
			void handleEvents(sf::Event sfEvent) override;

			/// <summary>
			/// Updates the player entity.
			/// </summary>
			///
			/// <param name="deltaTime">
			/// The delta time for the update frequency rate.
			/// </param>
			void update(float deltaTime) override;

			/// <summary>
			/// Draws the player entity.
			/// </summary>
			void draw() override;

		protected:
			/// <summary>
			/// File path and name of the image containing the player entity's
			/// texture.
			/// </summary>
			const std::string ENTITY_TEXTURE = "assets/boid.png";
	};
}

#endif