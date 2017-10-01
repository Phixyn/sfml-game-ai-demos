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

	GameAIDemos::Game game(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	game.addScene(std::make_unique<GameAIDemos::LevelScene>(game, BACKGROUND_IMAGE));
	game.mainLoop();

	return 0;
}
