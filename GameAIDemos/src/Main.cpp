#include "../include/GameWindow.hpp"

int main()
{
	const unsigned int WINDOW_WIDTH = 800;
	const unsigned int WINDOW_HEIGHT = 600;
	const std::string WINDOW_TITLE = "SFML Game AI Demos";

	GameAIDemos::GameWindow gameWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (gameWindow.isOpen())
	{
		gameWindow.handleEvents();
		gameWindow.clear();
		gameWindow.draw(shape);
		gameWindow.render();
	}

	return 0;
}
