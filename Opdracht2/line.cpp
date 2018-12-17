#include <SFML/Graphics.hpp>
#include "line.hpp"

line::line(sf::Vector2f position, sf::Color c, sf::Vector2f size) :
	position{ position },
	c(c),
	size{ size }
{}

void line::move(const sf::Vector2f & delta) {
	position += delta;
}

void line::jump(const sf::Vector2f & target) {
	position = target;
}


void line::draw(sf::RenderWindow & window) const {
	sf::RectangleShape line;
	line.setSize(size);
	line.setPosition(position);
	line.setRotation(45);
	line.setFillColor(c);
	window.draw(line);
}

sf::Vector2f line::getPosition() {
	return position;
}
