#include "../include/Game.hpp"
#include "../include/LevelScene.hpp"

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

	// TODO temporary placeholder entities for testing
	GameAIDemos::LiveEntity tempEntity = GameAIDemos::LiveEntity(100, sf::Vector2f(100.f, 100.f), sf::Vector2f(10.f, 10.f));
	tempEntity.setColor(sf::Color(sf::Color::Red));
	GameAIDemos::LiveEntity tempEntity2 = GameAIDemos::LiveEntity(100, sf::Vector2f(50.f, 50.f), sf::Vector2f(150.f, 150.f));

	// Create game and level scene instances
	GameAIDemos::Game game(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	GameAIDemos::LevelScene testScene = GameAIDemos::LevelScene(game, BACKGROUND_IMAGE);
	// Spawn entities in level scene
	testScene.spawnLiveEntity(tempEntity);
	testScene.spawnLiveEntity(tempEntity2);
	testScene.spawnLiveEntity(100, sf::Vector2f(50.f, 50.f), sf::Vector2f(250.f, 250.f));
	// Add scene to game and start main loop
	game.addScene(std::make_unique<GameAIDemos::LevelScene>(testScene));
	game.mainLoop();

	return 0;
}
