#ifndef _RECTANGLE_HPP
#define _RECTANGLE_HPP

#include "drawable.hpp"

class rectangle : public drawable{

public:

	rectangle(sf::Vector2f position, sf::Color c, int number, sf::Vector2f size = sf::Vector2f{ 20.0, 10.0 });
	void move(const sf::Vector2f & delta);
	void jump(const sf::Vector2f & delta) override;
	void draw(sf::RenderWindow & window) const override;
	void drawText() const;
	sf::Vector2f getSize() const override;

	void rectangle::reset();

	sf::Vector2f getPosition() override;
	sf::FloatRect getGlobalBounds() const override;

	sf::Color getColor() const override;

	bool isSet();

	void setElement(int cross); // give par for checking which element should be shown
	int getNumber();

private:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color c;
	int cross;
	int number;


};

#endif
