#include "../include/Game.hpp"
#include "../include/LevelScene.hpp"
#include "../include/DefendEntityState.hpp"
#include "../include/AttackEntityState.hpp"

/// <summary>
/// Entry point for the game.
/// </summary>
int main()
{
	const unsigned int WINDOW_WIDTH = 800;
	const unsigned int WINDOW_HEIGHT = 600;
	const std::string WINDOW_TITLE = "SFML Game AI Demos";
	// TODO: Temporary, asset doesn't exist but arg is required
	const std::string BACKGROUND_IMAGE = "assets/background.png";
	const std::string ENTITY_TEXTURE = "assets/boid.png";

	// Placeholder entities for testing / demo
	GameAIDemos::LiveEntity tempEntity = GameAIDemos::LiveEntity(100, sf::Vector2f(32.0f, 32.0f), sf::Vector2f(10.f, 150.f));
	tempEntity.setTexture(ENTITY_TEXTURE);
	GameAIDemos::LiveEntity tempEntity2 = GameAIDemos::LiveEntity(100, sf::Vector2f(32.0f, 32.0f), sf::Vector2f(150.f, 150.f));
	tempEntity2.setTexture(ENTITY_TEXTURE);
	tempEntity2.setVelocity(sf::Vector2f(0.25f, 0.0f));
	tempEntity2.setState(new GameAIDemos::DefendEntityState());
	GameAIDemos::LiveEntity tempEntity3 = GameAIDemos::LiveEntity(100, sf::Vector2f(32.0f, 32.0f), sf::Vector2f(250.f, 250.f));
	tempEntity3.setTexture(ENTITY_TEXTURE);
	tempEntity3.setVelocity(sf::Vector2f(0.25f, 0.0f));
	tempEntity3.setState(new GameAIDemos::AttackEntityState(&tempEntity2));

	// Create game and level scene instances
	GameAIDemos::Game game(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	GameAIDemos::LevelScene testScene = GameAIDemos::LevelScene(game, BACKGROUND_IMAGE);
	// Spawn entities in level scene
	testScene.spawnLiveEntity(tempEntity);
	testScene.spawnLiveEntity(tempEntity2);
	testScene.spawnLiveEntity(tempEntity3);

	// It works, but no default texture means the sprite won't be drawn
	// testScene.spawnLiveEntity(100, sf::Vector2f(50.f, 50.f), sf::Vector2f(250.f, 250.f));
	// Add scene to game and start main loop
	game.addScene(std::make_unique<GameAIDemos::LevelScene>(testScene));
	game.mainLoop();

	return 0;
}
