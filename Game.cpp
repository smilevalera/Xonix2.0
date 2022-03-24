#include <SFML/Graphics.hpp>

#include "const.h"
#include "Game.h"

Game::Game(): window(sf::VideoMode(N*ts,M*ts),"Xonix Game!"), 
player(100.f,100.f)
{
	window.setFramerateLimit(60);
}

void Game::play(){
	while (window.isOpen()) {
		check_event();
		update();
		draw();
		
	}
}
void Game::check_event(){

	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {

			window.close();
		}
	}
}
void Game::update(){
	player.update();
}
void Game::draw(){
	window.clear();
	player.draw(window);
	window.display();

}
