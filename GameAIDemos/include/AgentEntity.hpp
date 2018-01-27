#ifndef AGENT_ENTITY_H
#define AGENT_ENTITY_H

#include "PlayerEntity.hpp"

namespace GameAIDemos
{
	/// <summary>
	/// Subclass of <see cref="LiveEntity">LiveEntity</see> for the intelligent
	/// agent entity. An agent entity can seek or flee from targets, or it can
	/// be in idle state.
	/// </summary>
	class AgentEntity : public LiveEntity
	{
		public:
			/// <summary>
			/// Default constructor taking parameters for the entity's health,
			/// size, position and a reference to the player entity. The player
			/// entity is the target of the agent entity. The agent will either
			/// flee from or seek this target.
			/// </summary>
			///
			/// <param name="health">
			/// The health points of the agent entity.
			/// </param>
			/// <param name="size">
			/// A SFML Vector2f containing the agent entity's size.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the agent entity's position on the
			/// game scene.
			/// </param>
			/// <param name="player">
			/// A reference to the player entity in the game.
			/// </param>
			///
			/// <seealso cref="PlayerEntity" />
			AgentEntity(int health, sf::Vector2f size, sf::Vector2f position, PlayerEntity& player);

			/// <summary>
			/// Overloaded constructor taking an additional parameter for the
			/// entity's speed.
			/// </summary>
			///
			/// <param name="health">
			/// The health points of the agent entity.
			/// </param>
			/// <param name="size">
			/// A SFML Vector2f containing the agent entity's size.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the agent entity's position on the
			/// game scene.
			/// </param>
			/// <param name="speed">
			/// The movement speed of the agent entity.
			/// </param>
			/// <param name="player">
			/// A reference to the player entity in the game.
			/// </param>
			///
			/// <seealso cref="PlayerEntity" />
			AgentEntity(int health, sf::Vector2f size, sf::Vector2f position, float speed, PlayerEntity& player);

			/// <summary>
			/// Handles events specific to the agent entity.
			/// </summary>
			///
			/// <param name="sfEvent">
			/// A SFML event (e.g. generated user input) object.
			/// </param>
			void handleEvents(sf::Event sfEvent) override;

			/// <summary>
			/// Updates the agent entity.
			/// </summary>
			///
			/// <param name="deltaTime">
			/// The delta time for the update frequency rate.
			/// </param>
			void update(float deltaTime) override;

			/// <summary>
			/// Draws the agent entity.
			/// </summary>
			void draw() override;

		protected:
			/// <summary>
			/// File path and name of the image containing the agent entity's
			/// texture.
			/// </summary>
			const std::string ENTITY_TEXTURE = "assets/boid.png";
			/// <summary>
			/// A pointer to a PlayerEntity object, necessary for state classes
			/// to access information about the player (such as its position),
			/// in order to seek or flee from them.
			/// </summary>
			///
			/// <seealso cref="PlayerEntity" />
			PlayerEntity* m_playerPtr;
	};
}

#endif