#pragma once
#include "player.h"
class Game {
public:
	Game();
	void play();
private:
	void check_event();
	void update();
	void draw();

	sf::RenderWindow window;
	Player player;
};