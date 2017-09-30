#include "../include/Game.hpp"

/// <summary>
/// Entry point for the game.
/// </summary>
int main()
{
	const unsigned int WINDOW_WIDTH = 800;
	const unsigned int WINDOW_HEIGHT = 600;
	const std::string WINDOW_TITLE = "SFML Game AI Demos";

	GameAIDemos::Game game(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	game.mainLoop();

	return 0;
}
