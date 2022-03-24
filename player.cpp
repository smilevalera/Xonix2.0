#include "const.h"
#include "player.h"

Player::Player(float x, float y) {
	texture.loadFromFile("tiles2.0_1.png");
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}
void Player::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}
void Player::update(){
    float speedx = PLAYER_SPEEDX;
    float speedy = PLAYER_SPEEDY;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
        sprite.getPosition().x > 0
        )
    {
        sprite.move(-speedx, 0);
    }
    else
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
            sprite.getPosition().x < WINDOW_WIDTH - getWidth()
            )
        {
            sprite.move(speedx, 0);
        }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
        sprite.getPosition().y > 0
        )
    {
        sprite.move(0,-speedy);
    }
    else
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
            sprite.getPosition().x < WINDOW_HEIGHT - getHeight()
            )
        {
            sprite.move(0, speedy);
        }
}

size_t Player::getWidth() { return sprite.getLocalBounds().width; }
size_t Player::getHeight() { return sprite.getLocalBounds().height; }
sf::FloatRect Player::getHitBox() { return sprite.getLocalBounds(); }
sf::Vector2f Player::getPosition() { return sprite.getPosition(); }
