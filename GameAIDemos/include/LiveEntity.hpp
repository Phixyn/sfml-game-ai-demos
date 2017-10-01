#ifndef LIVE_ENTITY_H
#define LIVE_ENTITY_H

#include "Entity.hpp"

namespace GameAIDemos
{
	/// <summary>
	/// Subclass of <see cref="Entity">Entity</see> for live entities.
	/// Examples of live entities are NPCs, monsters and a player character.
	/// </summary>
	class LiveEntity : public Entity
	{
		public:
			/// <summary>
			/// Default constructor taking parameters for the entity's health
			/// and attack power.
			/// </summary>
			///
			/// <param name="health">
			/// The health points of the live entity.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the entity's position on the
			/// game scene.
			/// </param>
			LiveEntity(int health, sf::Vector2f position);

			/// <summary>
			/// Overloaded constructor taking an additional parameter for the
			/// entity's speed.
			/// </summary>
			///
			/// <param name="health">
			/// The health points of the live entity.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the entity's position on the
			/// game scene.
			/// </param>
			/// <param name="speed">
			/// The movement speed of the live entity.
			/// </param>
			LiveEntity(int health, sf::Vector2f position, float speed);

			/// <summary>
			/// Handles events specific to the live entity.
			/// </summary>
			void handleEvents() override;

			/// <summary>
			/// Updates the live entity.
			/// </summary>
			///
			/// <param name="deltaTime">
			/// The delta time for the update frequency rate.
			/// </param>
			void update(float deltaTime) override;

			/// <summary>
			/// Draws the live entity.
			/// </summary>
			void draw() override;

			// TODO: animate method?
			/// <summary>
			/// Handles live entity collision.
			/// TODO: Not yet (fully) implemented.
			/// </summary>
			///
			/// <param name="direction">
			/// A SFML Vector2f object containing a direction vector.
			/// </param>
			void onCollision(sf::Vector2f direction);

			/// <summary>
			/// Returns a value which specifies if the entity is aggressive.
			/// If a live entity is aggressive, it may attack other entities
			/// (such as the player).
			/// </summary>
			///
			/// <returns>
			/// A boolean specifying if the entity is aggressive.
			/// </returns>
			bool isAggressive();

			/// <summary>
			/// Returns a value which specifies if the live entity is dead.
			/// </summary>
			///
			/// <returns>
			/// A boolean specifying if the live entity is dead.
			/// </returns>
			bool isDead();

			/// <summary>
			/// Sets the live entity's <see cref="m_dead">m_dead</see> member
			/// variable, which specifies if the entity is dead.
			/// </summary>
			///
			/// <param name="dead">
			/// A boolean specifying if the entity is dead.
			/// </param>
			void setDead(bool dead);

			// TODO: Direction handling
			/// <summary>
			/// TODO: Not yet implemented.
			/// </summary>
			/// 
			/// <returns>
			/// A SFML Vector2f containing the entity's direction.
			/// </returns>
			sf::Vector2f getDirection();

			/// <summary>
			/// Not yet implemented.
			/// </summary>
			/// <param name="direction">
			/// A SFML Vector2f containing the entity's direction.
			/// </param>
			void setDirection(sf::Vector2f direction);
		protected:
			int m_health;
			float m_speed;
			bool m_aggressive;
			bool m_dead;
			sf::Vector2f m_velocity;
			// sf::Vector2f m_direction;
	};
}

#endif