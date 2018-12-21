#include <iostream>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "rectangle.hpp"
#include "drawable.hpp"
#include <vector>
#include "makeSetCommand.hpp"
#include "inputHandler.hpp"


sf::Vector2f Vector2f_from_Vector2i(const sf::Vector2i & rhs) {
	return sf::Vector2f(
		static_cast< float >(rhs.x),
		static_cast< float >(rhs.y)
	);
}


bool checkWin(std::vector<int> setPosition) {
	std::vector<int> setPosition1;
	std::vector<int> setPosition2;
	for (unsigned int i = 0; i < setPosition.size(); i++) {
		if (i % 2 == 0) {
			setPosition1.push_back(setPosition[i]);
		}
		else {
			setPosition2.push_back(setPosition[i]);
		}
	}

	if ((std::find(setPosition1.begin(), setPosition1.end(), 1) != setPosition1.end() &&
		std::find(setPosition1.begin(), setPosition1.end(), 2) != setPosition1.end() &&
		std::find(setPosition1.begin(), setPosition1.end(), 3) != setPosition1.end() )
		||
		(std::find(setPosition1.begin(), setPosition1.end(), 4) != setPosition1.end() &&
			std::find(setPosition1.begin(), setPosition1.end(), 5) != setPosition1.end() &&
			std::find(setPosition1.begin(), setPosition1.end(), 6) != setPosition1.end())
		||
		(std::find(setPosition1.begin(), setPosition1.end(), 7) != setPosition1.end() &&
			std::find(setPosition1.begin(), setPosition1.end(), 8) != setPosition1.end() &&
			std::find(setPosition1.begin(), setPosition1.end(), 9) != setPosition1.end())
		||
		(std::find(setPosition1.begin(), setPosition1.end(), 1) != setPosition1.end() &&
			std::find(setPosition1.begin(), setPosition1.end(), 4) != setPosition1.end() &&
			std::find(setPosition1.begin(), setPosition1.end(), 7) != setPosition1.end())
		||
		(std::find(setPosition1.begin(), setPosition1.end(), 2) != setPosition1.end() &&
			std::find(setPosition1.begin(), setPosition1.end(), 5) != setPosition1.end() &&
			std::find(setPosition1.begin(), setPosition1.end(), 8) != setPosition1.end())
		||

		(std::find(setPosition1.begin(), setPosition1.end(), 3) != setPosition1.end() &&
			std::find(setPosition1.begin(), setPosition1.end(), 6) != setPosition1.end() &&
			std::find(setPosition1.begin(), setPosition1.end(), 9) != setPosition1.end())
		||
		(std::find(setPosition1.begin(), setPosition1.end(), 1) != setPosition1.end() &&
			std::find(setPosition1.begin(), setPosition1.end(), 5) != setPosition1.end() &&
			std::find(setPosition1.begin(), setPosition1.end(), 9) != setPosition1.end())

		||
		(std::find(setPosition1.begin(), setPosition1.end(), 3) != setPosition1.end() &&
			std::find(setPosition1.begin(), setPosition1.end(), 5) != setPosition1.end() &&
			std::find(setPosition1.begin(), setPosition1.end(), 7) != setPosition1.end())
		) {

		return true;
	}
	if ((std::find(setPosition2.begin(), setPosition2.end(), 1) != setPosition2.end() &&
		std::find(setPosition2.begin(), setPosition2.end(), 2) != setPosition2.end() &&
		std::find(setPosition2.begin(), setPosition2.end(), 3) != setPosition2.end())
		||
		(std::find(setPosition2.begin(), setPosition2.end(), 4) != setPosition2.end() &&
			std::find(setPosition2.begin(), setPosition2.end(), 5) != setPosition2.end() &&
			std::find(setPosition2.begin(), setPosition2.end(), 6) != setPosition2.end())
		||
		(std::find(setPosition2.begin(), setPosition2.end(), 7) != setPosition2.end() &&
			std::find(setPosition2.begin(), setPosition2.end(), 8) != setPosition2.end() &&
			std::find(setPosition2.begin(), setPosition2.end(), 9) != setPosition2.end())
		||
		(std::find(setPosition2.begin(), setPosition2.end(), 1) != setPosition2.end() &&
			std::find(setPosition2.begin(), setPosition2.end(), 4) != setPosition2.end() &&
			std::find(setPosition2.begin(), setPosition2.end(), 7) != setPosition2.end())
		||
		(std::find(setPosition2.begin(), setPosition2.end(), 2) != setPosition2.end() &&
			std::find(setPosition2.begin(), setPosition2.end(), 5) != setPosition2.end() &&
			std::find(setPosition2.begin(), setPosition2.end(), 8) != setPosition2.end())
		||

		(std::find(setPosition2.begin(), setPosition2.end(), 3) != setPosition2.end() &&
			std::find(setPosition2.begin(), setPosition2.end(), 6) != setPosition2.end() &&
			std::find(setPosition2.begin(), setPosition2.end(), 9) != setPosition2.end())
		||
		(std::find(setPosition2.begin(), setPosition2.end(), 1) != setPosition2.end() &&
			std::find(setPosition2.begin(), setPosition2.end(), 5) != setPosition2.end() &&
			std::find(setPosition2.begin(), setPosition2.end(), 9) != setPosition2.end())

		||
		(std::find(setPosition2.begin(), setPosition2.end(), 3) != setPosition2.end() &&
			std::find(setPosition2.begin(), setPosition2.end(), 5) != setPosition2.end() &&
			std::find(setPosition2.begin(), setPosition2.end(), 7) != setPosition2.end())
		) {

		return true;
	}

	return false;
}

int main(int argc, char *argv[]) {
	std::cout << "Starting application 01-02 static ball\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };

	bool setPlayer = 0;

	sf::Color c = sf::Color(150, 0, 0);
	sf::Color c1 = sf::Color(250, 0, 200);

	rectangle my_rectangleOne{ sf::Vector2f{ 0.0, 0.0  }, c, 1, sf::Vector2f{ 210.0 , 159.0 } };
	rectangle my_rectangleTwo{ sf::Vector2f{ 213.0, 0.0 }, c, 2, sf::Vector2f{ 210.0, 159.0 } };
	rectangle my_rectangleThree{ sf::Vector2f{ 427.0, 0.0 }, c, 3, sf::Vector2f{ 210.0, 159.0 } };
	rectangle my_rectangleFour{ sf::Vector2f{ 0.0, 160.0 }, c, 4, sf::Vector2f{ 210.0, 159.0 } };
	rectangle my_rectangleFive{ sf::Vector2f{ 213.0, 160.0 }, c, 5, sf::Vector2f{ 210.0, 159.0 } };
	rectangle my_rectangleSix{ sf::Vector2f{ 427.0, 160.0 }, c, 6, sf::Vector2f{ 210.0, 159.0 } };
	rectangle my_rectangleSeven{ sf::Vector2f{ 0.0, 320.0 }, c, 7, sf::Vector2f{ 210.0, 159.0 } };
	rectangle my_rectangleEight{ sf::Vector2f{ 213.0, 320.0 }, c, 8, sf::Vector2f{ 210.0, 159.0 } };
	rectangle my_rectangleNine{ sf::Vector2f{ 427.0, 320.0 }, c, 9, sf::Vector2f{ 210.0, 159.0 } };

	const int rectangleListSize = 9;
	rectangle * rectangleList[9] = { &my_rectangleOne, &my_rectangleTwo, &my_rectangleThree, 
		&my_rectangleFour, &my_rectangleFive , &my_rectangleSix, &my_rectangleSeven, &my_rectangleEight, &my_rectangleNine };
	
	std::vector<int> setPosition = {};

	makeSetCommand command;
	inputHandler ih(rectangleList);
	bool done = 0;

	window.clear();
	for (int i = 0; i < rectangleListSize; i++) {
		rectangleList[i]->draw(window);
	}
	window.display();

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed && !done) {
				sf::Vector2f pos = Vector2f_from_Vector2i(sf::Mouse::getPosition(window));

				rectangle * matchedRectangle = ih.handleInput(pos);
				if (matchedRectangle) {
					command.execute(matchedRectangle, setPlayer);
					setPlayer = !setPlayer;
					setPosition.push_back(matchedRectangle->getNumber());
					if (checkWin(setPosition)) {
						done = true;
					}
				}
			}

			if (event.type==sf::Event::KeyPressed){
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
					if (setPosition.size() > 0) {
						int index = setPosition.back();
						command.execute(rectangleList[index - 1], -1);
						setPosition.pop_back();
					}
					
				}
			}
		}
		window.clear();
		for (int i = 0; i < rectangleListSize; i++) {
			rectangleList[i]->draw(window);
		}
		window.display();
		sf::sleep(sf::milliseconds(20));
	}
	std::cout << "Terminating application\n";
	return 0;
}

