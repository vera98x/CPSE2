#include "inputHandler.hpp"
#include <iostream>


inputHandler::inputHandler() {}


sf::Vector2f inputHandler::Vector2f_from_Vector2i(const sf::Vector2i & rhs) {
	return sf::Vector2f(
		static_cast<float>(rhs.x),
		static_cast<float>(rhs.y)
	);
}

rectangle* inputHandler::handleInput(const std::array<std::shared_ptr<rectangle>, 9> & rectangleList, bool graph, sf::RenderWindow * window, bool &undo) {
	if (graph) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2f pos = Vector2f_from_Vector2i(sf::Mouse::getPosition(*window));
			for (unsigned int i = 0; i < 9; i++) {
				if (rectangleList.at(i)->getGlobalBounds().contains(pos) && !rectangleList.at(i)->isSet()) {
					return rectangleList.at(i).get();
				}

			}
		}
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window->close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
					undo = 1;
				}
			}
		}
	}
	else {
		std::cout << "choose your position: ";
		int x;
		char temp;
		int y;
		try {
			//std::cin >> x;
			if (!((std::cin >> x)) && (x >= 1 && x <=3) ) {
				throw 20;
			}
		}
		catch (...) {
			std::cout << "x is no correct coordinate \n";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			return NULL;
		}

		try {
			if (!(std::cin >> temp)) {
				throw(20);
			}
		}
		catch (...) {
			std::cout << " x or y is wrong \n";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			
			return NULL;
		}

		try {
			if ((!(std::cin >> y)) && (y >= 1 && y <= 3)) {
				throw(20);
			}
		}
		catch (...) {
			std::cout << "y is no correct coordinate \n";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			return NULL;
		}

		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		if (x == -1 && y == -1) {
			undo = 1;
			return NULL;
		}

		std::cout << "\n ";
		if (x > 0 && x <= 3 && y > 0 && y <= 3) {
			if ((x + (3 * (y - 1)) >= 0) && (x + (3 * (y - 1)) <= 9)) {
				return rectangleList.at((x + (3 * (y - 1)) - 1)).get();
			}
		}
	}
	return NULL;
}
