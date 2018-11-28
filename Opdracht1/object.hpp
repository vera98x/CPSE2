#ifndef _OBJECT_HPP
#define _OBJECT_HPP

#include <SFML/Graphics.hpp>

class object {
public:

	virtual void draw(sf::RenderWindow & window) const = 0;
};

#endif
