#ifndef _INPUTHANDLER_HPP
#define _INPUTHANDLER_HPP

#include "command.hpp"
#include "rectangle.hpp"

class inputHandler {
private:
	rectangle * rectangleList[9];

public:

	inputHandler(rectangle * rl[9]) {
		for (int i = 0; i < 9; i++) {
			rectangleList[i] = rl[i];
		}
	}

	rectangle * handleInput(sf::Vector2f pos) {
		for (unsigned int i = 0; i < 9; i++) {
			if (rectangleList[i]->getGlobalBounds().contains(pos) && !rectangleList[i]->isSet()) {
				return rectangleList[i];
			}
			
		}
		return NULL;
	}

};


#endif // !_INPUTHANDLER_HPP
