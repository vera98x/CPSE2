#ifndef _PICTURE_HPP
#define _PICTURE_HPP

#include "drawable.hpp"

class picture : public drawable {

public:

	picture(sf::Vector2f position, sf::Texture texture, std::string filename);
	void move(const sf::Vector2f & delta);
	void jump(const sf::Vector2f & delta) override;
	void draw(sf::RenderWindow & window) const override;
	sf::Vector2f getPosition() override;
	sf::FloatRect getGlobalBounds() const override {
		sf::Sprite sprite;
		sprite.setTexture(texture);
		sprite.setPosition(position);
		return sprite.getGlobalBounds();

	}
	sf::Color getColor() const { return sf::Color(sf::Color::Black); };
	sf::Vector2f getSize() const { return { -1, -1 }; };
	std::string getFilename() const;

private:
	sf::Vector2f position;
	sf::Texture texture;
	sf::String filename;
	


};

#endif
