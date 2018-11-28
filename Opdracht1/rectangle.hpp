#ifndef _RECTANGLE_HPP
#define _RECTANGLE_HPP

#include "object.hpp"

class rectangle : public object{

public:

	rectangle(sf::Vector2f position, sf::Color c, sf::Vector2f size = sf::Vector2f{ 20.0, 10.0 });
	void move(const sf::Vector2f & delta);
	void jump(const sf::Vector2f & delta);
	void draw(sf::RenderWindow & window) const override;
	sf::Vector2f getPosition();
	sf::FloatRect getGlobalBounds() {
		sf::RectangleShape rectangle;
		rectangle.setSize(size);
		rectangle.setPosition(position);
		return rectangle.getGlobalBounds();

	}

private:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color c;


};

#endif
