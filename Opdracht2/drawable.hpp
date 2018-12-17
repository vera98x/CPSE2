#ifndef _DRAWABLE_HPP
#define _DRAWABLE_HPP

#include <SFML/Graphics.hpp>

class drawable {
public:

	virtual void draw(sf::RenderWindow & window) const = 0;
	virtual sf::FloatRect getGlobalBounds() const = 0;
	virtual void jump(const sf::Vector2f & delta) = 0;
	virtual sf::Vector2f getPosition() = 0;
	virtual sf::Color getColor() const = 0;
	virtual sf::Vector2f getSize() const = 0;
	virtual std::string getFilename() const = 0;
};

#endif
