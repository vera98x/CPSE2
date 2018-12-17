#include <SFML/Graphics.hpp>
#include "picture.hpp"

picture::picture(sf::Vector2f position, sf::Texture texture, std::string filename) :
	position{ position },
	texture(texture),
	filename(filename)
{}

void picture::move(const sf::Vector2f & delta) {
	position += delta;
}

void picture::jump(const sf::Vector2f & target) {
	position = target;
}


void picture::draw(sf::RenderWindow & window) const {
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(position);
	window.draw(sprite);
}

sf::Vector2f picture::getPosition() {
	return position;
}

std::string picture::getFilename()const {
	return filename;
}