#include <iostream>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "rectangle.hpp"
#include "object.hpp"


int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-02 static ball\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	
	sf::Color c = sf::Color(150, 0, 0);
	sf::Color c1 = sf::Color(250, 0, 200);

	ball my_ball{ sf::Vector2f{ 320.0, 240.0 }, sf::Vector2f{ 3, 7 } };
	rectangle my_rectangleUp{ sf::Vector2f{ 0.0, 0.0 }, c, sf::Vector2f{ 640 , 30.0 } };
	rectangle my_rectangleLeft{ sf::Vector2f{ 0.0, 0.0 }, c, sf::Vector2f{ 30.0, 480 } };
	rectangle my_rectangleRight{ sf::Vector2f{ 610, 0.0 }, c, sf::Vector2f{ 30.0, 480.0 } };
	rectangle my_rectangleBottom{ sf::Vector2f{ 0.0, 450.0 }, c, sf::Vector2f{ 640, 30.0 } };
	rectangle my_rectangle{ sf::Vector2f{ 80.0, 80.0 }, c1, sf::Vector2f{ 270.0, 30.0 } };

	const int rectangleListSize = 5;
    rectangle * rectangleList[rectangleListSize] = { &my_rectangleUp, &my_rectangleLeft, &my_rectangleRight, &my_rectangleBottom, &my_rectangle };

	sf::Rect<float> intersectionRectangle;
	intersectionRectangle.width = 0;
	intersectionRectangle.height = 0;

	window.clear();
	my_ball.draw(window);
	for (int i = 0; i < rectangleListSize; i++) {
		rectangleList[i] -> draw(window);
	}
	window.display();

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				my_rectangle.move(sf::Vector2f{ -7, 0 });
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				my_rectangle.move(sf::Vector2f{ +7, 0 });
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				my_rectangle.move(sf::Vector2f{ 0, -7 });
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				my_rectangle.move(sf::Vector2f{ 0, +7 });
			}
			

		}

		my_ball.update();

		for (int i = 0; i < rectangleListSize; i++) {
				if (my_ball.getGlobalBounds().intersects(rectangleList[i]->getGlobalBounds(), intersectionRectangle)) {

					if (int(my_ball.getPosition().x) == int(intersectionRectangle.left) && intersectionRectangle.height == my_ball.getSize() * 2) {
						std::cout << "leeeeft";
						my_ball.bounce(sf::Vector2f{ -1, 1 });
						while ((intersectionRectangle.width < 59 && intersectionRectangle.width > 7) 
							|| (intersectionRectangle.height < 59 && intersectionRectangle.height > 7)){ 
							my_ball.update();
							my_ball.getGlobalBounds().intersects(rectangleList[i]->getGlobalBounds(), intersectionRectangle);
						}
					}
					else if (int(my_ball.getPosition().x + int(my_ball.getSize() * 2) - 1) == int(intersectionRectangle.left)) {
						std::cout << "riiiiight";
						my_ball.bounce(sf::Vector2f{ -1, 1 });
						while ((intersectionRectangle.width < 59 && intersectionRectangle.width > 7)
							|| (intersectionRectangle.height < 59 && intersectionRectangle.height > 7)) {
							my_ball.update();
							my_ball.getGlobalBounds().intersects(rectangleList[i]->getGlobalBounds(), intersectionRectangle);
						}
					}
					else {
						my_ball.bounce(sf::Vector2f{ 1, -1 });
						while ((intersectionRectangle.width < 59 && intersectionRectangle.width > 7)
							|| (intersectionRectangle.height < 59 && intersectionRectangle.height > 7)) {
							my_ball.update();
							my_ball.getGlobalBounds().intersects(rectangleList[i]->getGlobalBounds(), intersectionRectangle);
						}
					}

				}

			
		}

		window.clear();
		my_ball.draw(window);
		for (int i = 0; i < rectangleListSize; i++) {
			rectangleList[i] -> draw(window);
		}
		window.display();
		sf::sleep(sf::milliseconds(20));
	}
	std::cout << "Terminating application\n";
	return 0;
}

