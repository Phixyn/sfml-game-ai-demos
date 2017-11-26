#ifndef LEVEL_SCENE_H
#define LEVEL_SCENE_H

#include "Scene.hpp"
#include "LiveEntity.hpp"
#include "InfoPanel.hpp"

namespace GameAIDemos
{
	/// <summary>
	/// Subclass of <see cref="Scene">Scene</see> for game AI demo levels.
	/// </summary>
	class LevelScene : public Scene
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
			/// <param name="backgroundImagePath">
			/// A string containing the path for the background image file.
			/// </param>
			LevelScene(Game &game, std::string backgroundImagePath);

			/// <summary>
			/// Handles events specific to the level scene.
			/// </summary>
			///
			/// <param name="sfEvent">
			/// A SFML event (e.g. generated user input) instance.
			/// </param>
			void handleEvents(sf::Event sfEvent) override;

			/// <summary>
			/// Updates the level scene.
			/// </summary>
			///
			/// <param name="deltaTime">
			/// The delta time for the update frequency rate.
			/// </param>
			void update(float deltaTime) override;

			/// <summary>
			/// Draws the level scene.
			/// </summary>
			void draw() override;

			/// <summary>
			/// Sets the scene's background image.
			/// </summary>
			///
			/// <param name="imageFilePath">
			/// A string containing the path for the level's background
			/// image file.
			/// </param>
			void setBackgroundImage(std::string imageFilePath);

			/// <summary>
			/// Spawns a new live entity in the level scene.
			/// </summary>
			///
			/// <param name="entity">
			/// Instance of <see cref="LiveEntity">LiveEntity</see> to be added
			/// to the level scene.
			/// </param>
			/// <seealso cref="LiveEntity" />
			void spawnLiveEntity(LiveEntity entity);
			/// <summary>
			/// Spawns a new live entity in the level scene.
			/// </summary>
			///
			/// <param name="health">
			/// The health points of the live entity.
			/// </param>
			/// <param name="size">
			/// A SFML Vector2f containing the live entity's size.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the entity's position on the
			/// game scene.
			/// </param>
			/// <seealso cref="LiveEntity" />
			void spawnLiveEntity(int health, sf::Vector2f size, sf::Vector2f position);
			/// <summary>
			/// Spawns a new live entity in the level scene.
			/// </summary>
			///
			/// <param name="health">
			/// The health points of the live entity.
			/// </param>
			/// <param name="size">
			/// A SFML Vector2f containing the live entity's size.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the entity's position on the
			/// game scene.
			/// </param>
			/// <param name="speed">
			/// The movement speed of the live entity.
			/// </param>
			/// <seealso cref="LiveEntity" />
			void spawnLiveEntity(int health, sf::Vector2f size, sf::Vector2f position, float speed);
		private:
			/// <summary>
			/// Size (in pixels) of the textures used by sprites in the scene.
			/// </summary>
			float m_textureSize = 48;
			// std::vector<GameAIDemos::TileEntity> m_tileEntities;
			/// <summary>
			/// Vector containing <see cref="LiveEntity">LiveEntity</see>
			/// objects to be used in the scene.
			/// </summary>
			///
			/// <seealso cref="Entity" />
			/// <seealso cref="LiveEntity" />
			std::vector<GameAIDemos::LiveEntity> m_liveEntities;
			// std::vector<sf::RectangleShape> m_tileSprites;
			/// <summary>
			/// Map containing entries with an ID of a texture and an instance
			/// of SFML Texture.
			/// </summary>
			std::map<std::string, sf::Texture> m_levelTextures;
			/// <summary>
			/// SFML Texture object for the level's background texture.
			/// </summary>
			sf::Texture m_backgroundTexture;
			/// <summary>
			/// SFML Sprite object for the level's background sprite.
			/// </summary>
			sf::Sprite m_backgroundSprite;
	};
}

#endif