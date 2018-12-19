#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class ball : public drawable {
public:

	ball( sf::Vector2f position, sf::Vector2f speed, sf::Color c, float size = 30.0 );
	void move(const sf::Vector2f & delta);
	void jump(const sf::Vector2f & delta) override;
	void draw( sf::RenderWindow & window ) const override;
	void update();
	sf::Vector2f getPosition() override;
	sf::Vector2f getSize() const override {
		return sf::Vector2f(size, 0);
	}
	sf::FloatRect getGlobalBounds() const override {
		sf::CircleShape circle;
		circle.setRadius(size);
		circle.setPosition(position);
		return circle.getGlobalBounds();

	}
	sf::Color getColor() const override {
		return c;
	}

	void bounce(sf::Vector2f delta) {
		speed.x *= delta.x;
		speed.y *= delta.y;
	}

private:
	sf::Vector2f position;
	sf::Vector2f speed;
	sf::Color c;
	float size;
	
};

#endif
