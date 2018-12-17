#ifndef _LINE_HPP
#define _LINE_HPP

#include "drawable.hpp"

class line : public drawable {

public:

	line(sf::Vector2f position, sf::Color c, sf::Vector2f size = sf::Vector2f{ 70.0, 2.0 });
	void move(const sf::Vector2f & delta);
	void jump(const sf::Vector2f & delta) override;
	void draw(sf::RenderWindow & window) const override;
	sf::Vector2f getSize() const override {
		return size;
	}
	sf::Vector2f getPosition() override;
	sf::FloatRect getGlobalBounds() const override {
		sf::RectangleShape rectangle;
		rectangle.setSize(size);
		rectangle.setPosition(position);
		return rectangle.getGlobalBounds();

	}
	sf::Color getColor() const override {
		return c;
	}
	virtual std::string getFilename() const { return ""; };

private:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color c;


};

#endif
