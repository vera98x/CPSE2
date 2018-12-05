#include <SFML/Graphics.hpp>
#include "rectangle.hpp"

rectangle::rectangle(sf::Vector2f position, sf::Color c, sf::Vector2f size) :
	position{ position },
	c (c),
	size{ size }
{}

void rectangle::move(const sf::Vector2f & delta) {
	position += delta;
}

void rectangle::jump(const sf::Vector2f & target) {
	position = target;
}


void rectangle::draw(sf::RenderWindow & window) const {
	sf::RectangleShape rectangleShape;
	rectangleShape.setSize(size);
	rectangleShape.setPosition(position);
	rectangleShape.setFillColor(c);
	window.draw(rectangleShape);
}

sf::Vector2f rectangle::getPosition() {
	return position;
}
