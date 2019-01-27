#include <iostream>
#include <SFML/Graphics.hpp>
#include "rectangle.hpp"
#include "drawable.hpp"
#include <vector>
#include "inputHandler.hpp"
#include "Game.hpp"


bool getWhileCondition(bool graph, bool done, sf::RenderWindow* window) {
	if (graph) {
		return(window->isOpen());
	}
	else {
		return !done;
	}
}


int main(int argc, char *argv[]) {
	std::cout << "Starting application Tic-Tac-Toe\n";
	std::cout << "graphical interface?, press Y";

	bool graph = 0;
	char yes;
	std::cin >> yes;
	if (yes == 'Y' or yes == 'y') {
		graph = 1;
	}
	std::shared_ptr<sf::RenderWindow> window;
	if (graph) {
		window = std::make_shared<sf::RenderWindow>( sf::VideoMode{ 640, 480 }, "SFML window" );
	}
	bool setPlayer = 0;

	sf::Color c = sf::Color(150, 0, 0);
	sf::Color c1 = sf::Color(250, 0, 200);

	std::vector< sf::Vector2f> rx{ sf::Vector2f{0.0, 0.0}, sf::Vector2f{ 213.0, 0.0 }, sf::Vector2f{ 427.0, 0.0 }, sf::Vector2f{ 0.0, 160.0 }, sf::Vector2f{ 213.0, 160.0 }, sf::Vector2f{ 427.0, 160.0 }, sf::Vector2f{ 0.0, 320.0 }, sf::Vector2f{ 213.0, 320.0 }, sf::Vector2f{ 427.0, 320.0 } };

	Game game(graph, rx);
	inputHandler ih;
	bool done = 0;
	bool undo = 0;


	while (getWhileCondition(graph, done, window.get())) {
		
		if (!done) {
			rectangle * matchedRectangle = ih.handleInput(game.getRectangleList(), graph, window.get(), undo);

			game.action(matchedRectangle, done, undo);
			game.updateScreen(window.get());

			sf::sleep(sf::milliseconds(20));
		}
	}
	
	

}

