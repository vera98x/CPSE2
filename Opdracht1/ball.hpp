#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "object.hpp"

class ball : public object {
public:

	ball( sf::Vector2f position, sf::Vector2f speed, float size = 30.0 );
	void move(const sf::Vector2f & delta);
	void jump(const sf::Vector2f & delta);
	void draw( sf::RenderWindow & window ) const override;
	void update();
	sf::Vector2f getPosition();
	float getSize() {
		return size;
	}
	sf::FloatRect getGlobalBounds() {
		sf::CircleShape circle;
		circle.setRadius(size);
		circle.setPosition(position);
		return circle.getGlobalBounds();

	}

	void bounce(sf::Vector2f delta) {
		speed.x *= delta.x;
		speed.y *= delta.y;
	}

private:
	sf::Vector2f position;
	sf::Vector2f speed;
	float size;
	
};

#endif
