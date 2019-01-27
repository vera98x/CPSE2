#include <SFML/Graphics.hpp>
#include "rectangle.hpp"
#include <iostream>

rectangle::rectangle(sf::Vector2f position, sf::Color c, int number, sf::Vector2f size ) :
	position{ position },
	c(c),
	size{ size },
	number(number)
{
	cross = -1;
}

sf::Vector2f rectangle::getSize() const {
	return size;
}

void rectangle::move(const sf::Vector2f & delta) {
	position += delta;
}

void rectangle::jump(const sf::Vector2f & target) {
	position = target;
}

sf::FloatRect rectangle::getGlobalBounds() const {
	sf::RectangleShape rectangle;
	rectangle.setSize(size);
	rectangle.setPosition(position);
	return rectangle.getGlobalBounds();

}

sf::Color rectangle::getColor() const {
	return c;
}


void rectangle::draw(sf::RenderWindow & window) const {
	sf::RectangleShape rectangleShape;
	rectangleShape.setSize(size);
	rectangleShape.setPosition(position);

	sf::Texture texture;
	if (cross == 1) {
		texture.loadFromFile("cross.jpg");
	}
	else if (cross == 0) {
		texture.loadFromFile("circle.jpg");
	}
	

	rectangleShape.setTexture(&texture);

	rectangleShape.setFillColor(c);
		
	window.draw(rectangleShape);
}

void rectangle::drawText() const {
	if (cross == 0) {
		std::cout << "	O	";
	}
	else if (cross == 1) {
		std::cout << "	X	";
	}
	else {
		std::cout << "		";
	}
	 
}

sf::Vector2f rectangle::getPosition() {
	return position;
}

void rectangle::reset() {
	cross = -1;
}

bool rectangle::isSet() {
	if (cross == -1) {
		return false;
	}
	return true;
}

void rectangle::setElement(int cr) {
	
	cross = cr;

}

int rectangle::getNumber() {
	return number;
}
