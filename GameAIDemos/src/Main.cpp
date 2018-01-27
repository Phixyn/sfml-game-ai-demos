#include "../include/AgentEntity.hpp"
#include "../include/Game.hpp"
#include "../include/LevelScene.hpp"

/// <summary>
/// Entry point for the game.
/// </summary>
int main()
{
	// Game window properties
	const unsigned int WINDOW_WIDTH = 800;
	const unsigned int WINDOW_HEIGHT = 600;
	const std::string WINDOW_TITLE = "SFML Game AI Demos";
	// Initial entity health
	const int ENTITY_SPAWN_HEALTH = 100;
	// Entity sprite sizes
	const sf::Vector2f ENTITY_SIZE = sf::Vector2f(32.0f, 32.0f);
	// Coordinates for player entity spawn point (middle of the window)
	const float PLAYER_SPAWN_X = (float)((WINDOW_WIDTH / 2) - (ENTITY_SIZE.x / 2));
	const float PLAYER_SPAWN_Y = (float)((WINDOW_HEIGHT / 2) - (ENTITY_SIZE.y / 2));
	const std::string BACKGROUND_IMAGE = "assets/background.jpg";

	// Initialize entities to spawn at the start of the demo
	GameAIDemos::PlayerEntity player = GameAIDemos::PlayerEntity(ENTITY_SPAWN_HEALTH, ENTITY_SIZE, sf::Vector2f(PLAYER_SPAWN_X, PLAYER_SPAWN_Y));
	GameAIDemos::AgentEntity agentEntity1 = GameAIDemos::AgentEntity(ENTITY_SPAWN_HEALTH, ENTITY_SIZE, sf::Vector2f(10.f, 150.f), player);
	GameAIDemos::AgentEntity agentEntity2 = GameAIDemos::AgentEntity(ENTITY_SPAWN_HEALTH, ENTITY_SIZE, sf::Vector2f(150.f, 250.f), player);

	/* We can also set velocities for the entities before spawning them
	 * If this is done, their state will be idle (unless setState is used),
	 * but they will be cruising in space at the given velocity. */
	// seekEntity1.setVelocity(sf::Vector2f(0.25f, 0.0f));
	// fleeEntity1.setVelocity(sf::Vector2f(0.25f, 0.0f));

	// Initialize Game and LevelScene instances
	GameAIDemos::Game game(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	GameAIDemos::LevelScene testScene = GameAIDemos::LevelScene(game, player, BACKGROUND_IMAGE);

	// Spawn entities in level scene
	testScene.spawnLiveEntity(agentEntity1);
	testScene.spawnLiveEntity(agentEntity2);
	// This also works, but no default texture means the sprite won't be drawn and visible
	// testScene.spawnLiveEntity(100, sf::Vector2f(50.f, 50.f), sf::Vector2f(250.f, 250.f));

	// Add scene to game and start main loop
	game.addScene(std::make_unique<GameAIDemos::LevelScene>(testScene));
	game.mainLoop();

	return 0;
}
