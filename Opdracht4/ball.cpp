#include <SFML/Graphics.hpp>
#include "ball.hpp"

ball::ball(sf::Vector2f position, sf::Vector2f speed, sf::Color c, float size) :
	position{ position },
	speed (speed),
	c (c),
	size{ size }
{}

void ball::move(const sf::Vector2f & delta) {
	position += delta;
}

void ball::jump(const sf::Vector2f & target) {
	position = target;
}

void ball::update() {
	position += speed;
}


void ball::draw(sf::RenderWindow & window) const {
	sf::CircleShape circle;
	circle.setRadius( size );
	circle.setPosition( position );
	circle.setFillColor(c);
	window.draw( circle );
}

sf::Vector2f ball::getPosition() {
	return position;
}
