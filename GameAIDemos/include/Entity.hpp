#ifndef ENTITY_H
#define ENTITY_H

#include "InfoPanel.hpp"
#include "BaseEntityState.hpp"
#include "Logger.hpp"

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
			/// <param name="size">
			/// A SFML Vector2f containing the entity's size.
			/// </param>
			Entity(sf::Vector2f size);

			/// <summary>
			/// Overloaded constructor with an argument for the entity's
			/// position in the game.
			/// </summary>
			///
			/// <param name="size">
			/// A SFML Vector2f containing the entity's size.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the entity's position on the
			/// game scene.
			/// </param>
			Entity(sf::Vector2f size, sf::Vector2f position);

			/// <summary>
			/// Overloaded constructor with an argument for a file containing
			/// a texture for the entity.
			/// </summary>
			///
			/// <param name="size">
			/// A SFML Vector2f containing the entity's size.
			/// </param>
			/// <param name="textureFilePath">
			/// A string specifying a filename of a texture image for this
			/// entity.
			/// </param>
			Entity(sf::Vector2f size, std::string textureFilePath);

			/// <summary>
			/// Overloaded constructor with an argument for position and
			/// texture file.
			/// </summary>
			///
			/// <param name="size">
			/// A SFML Vector2f containing the entity's size.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the entity's position on the
			/// game scene.
			/// </param>
			/// <param name="textureFilePath">
			/// A string specifying a filename of a texture image for this
			/// entity.
			/// </param>
			Entity(sf::Vector2f size, sf::Vector2f position, std::string textureFilePath);

			/// <summary>
			/// Pure virtual method to handle events of the entity.
			/// </summary>
			///
			/// <param name="sfEvent">
			/// A SFML event (e.g. generated user input) instance.
			/// </param>
			virtual void handleEvents(sf::Event sfEvent) = 0;

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
			void setTexture(sf::Texture texture);
			/// <summary>
			/// Sets the texture for the entity after loading the texture from
			/// the given file path.
			/// </summary>
			///
			/// <param name="textureFilePath">
			/// A string specifying a filename of a texture image for this
			/// entity.
			/// </param>
			void setTexture(std::string textureFilePath);
			/// <summary>
			/// Sets the entity's rectangle's color. Most likely temporary and
			/// for debugging purposes.
			/// </summary>
			///
			/// <param name="color">
			/// A reference to a SFML Color object.
			/// </param>
			void setColor(sf::Color color);
			/// <summary>
			/// Sets the entity's sprite's color tint.
			/// </summary>
			///
			/// <param name="color">
			/// A reference to a SFML Color object.
			/// </param>
			void setSpriteColor(sf::Color color);
			/// <summary>
			/// Sets the position of the entity in the game scene.
			/// </summary>
			///
			/// <param name="position">
			/// A reference to a SFML Vector2f containing the new position
			/// for the entity on the game scene.
			/// </param>
			void setPosition(sf::Vector2f &position);
			/// <summary>
			/// Toggles the entity's information panel on or off, depending on
			/// its current state.
			/// </summary>
			void toggleInfoPanel();

			/// <summary>
			/// Gets the width of the entity's rectangle.
			/// </summary>
			///
			/// <returns>
			/// A float containing the rectangle's width.
			/// </returns>
			float getRectWidth();
			/// <summary>
			/// Gets the Height of the entity's rectangle.
			/// </summary>
			///
			/// <returns>
			/// A float containing the rectangle's Height.
			/// </returns>
			float getRectHeight();
			/// <summary>
			/// Gets the position of the entity in the game scene.
			/// </summary>
			///
			/// <returns>
			/// A SFML Vector2f containing the entity's position on the
			/// game scene.
			/// </returns>
			sf::Vector2f getPosition();

			/// <summary>
			/// Gets the entity's rectangle.
			/// </summary>
			///
			/// <returns>
			/// A SFML RectangleShape instance containing the entity's
			/// rectangle.
			/// </returns>
			sf::RectangleShape getRect();
			/// <summary>
			/// Gets the entity's sprite.
			/// </summary>
			///
			/// <returns>
			/// A SFML Sprite instance of the entity.
			/// </returns>
			sf::Sprite getSprite();
			/// <summary>
			/// Gets the entity's InfoPanel object.
			/// </summary>
			///
			/// <returns>
			/// A <see cref="InfoPanel">InfoPanel</see> instance of the entity.
			/// </returns>
			GameAIDemos::InfoPanel getInfoPanel();
			/// <summary>
			/// Returns a boolean indicating if this entity's info panel UI
			/// element is enabled and being displayed in the UI.
			/// </summary>
			///
			/// <returns>
			/// A boolean indicating if the entity's info panel is enabled.
			/// </returns>
			/// <seealso cref="InfoPanel" />
			bool isInfoPanelEnabled();

			/// <summary>
			/// Returns a boolean indicating if this entity has been selected
			/// by the user via a mouse click.
			/// </summary>
			///
			/// <returns>
			/// A boolean indicating if the entity is currently selected.
			/// </returns>
			bool isSelected();

			/// <summary>
			/// Toggles the entity's selected state to true or false, depending
			/// on its current value.
			/// </summary>
			void toggleSelected();

			/// <summary>
			/// Returns an instance of the BaseEntityState subclass for this
			/// entity's current state.
			/// </summary>
			///
			/// <returns>
			/// An instance of the current state of the entity.
			/// </returns>
			/// <seealso cref="BaseEntityState" />
			BaseEntityState* getState();
			/// <summary>
			/// Sets the entity's current state. Exits the entity's current
			/// state, sets the state and enters the new state.
			/// </summary>
			///
			/// <param name="state">
			/// A pointer to a new state object.
			/// </param>
			/// <seealso cref="BaseEntityState" />
			void setState(BaseEntityState* state);

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

			// Collision m_collision; // TODO: make this private or protected?
		protected:
			/// <summary>
			/// Width of the entity's rectangle.
			/// </summary>
			float m_rectWidth;
			/// <summary>
			/// Height of the entity's rectangle.
			/// </summary>
			float m_rectHeight;
			/// <summary>
			/// SFML Vector2f instance containing the position of the entity.
			/// </summary>
			sf::Vector2f m_position;
			/// <summary>
			/// SFML RectangleShape instance for the entity's rectangle.
			/// </summary>
			sf::RectangleShape m_rect;
			/// <summary>
			/// SFML Sprite instance for the entity's sprite.
			/// </summary>
			sf::Sprite m_sprite;
			/// <summary>
			/// SFML Texture instance for the entity's texture.
			/// </summary>
			sf::Texture m_texture;
			/// <summary>
			/// SFML Color instance for the entity's rectangle color.
			/// </summary>
			sf::Color m_color;

			/// <summary>
			/// Instance of <see cref="InfoPanel">InfoPanel</see> used for
			/// displaying entity information on screen.
			/// </summary>
			InfoPanel m_infoPanel;
			/// <summary>
			/// A boolean specifying if the entity's info panel should be
			/// displayed in the UI. An info panel displays useful information
			/// about an entity.
			/// </summary>
			/// <seealso cref="InfoPanel" />
			bool m_displayInfoPanel = false;

			/// <summary>
			/// A boolean specifying if the entity is currently selected by the
			/// user.
			/// </summary>
			bool m_isSelected = false;

			/// <summary>
			/// An instance of a BaseEntityState subclass, representing the
			/// current state of this entity.
			/// about an entity.
			/// </summary>
			/// <seealso cref="BaseEntityState" />
			BaseEntityState* m_state;

			/// <summary>
			/// Instance of <see cref="Logger">Logger</see> for logging.
			/// </summary>
			Logger m_logger;
	};
}

#endif
