#pragma once
#include "rectangle.hpp"
#include "command.hpp"
#include "makeCircleSetCommand.hpp"
#include "makeRectangleSetCommand.hpp"
#include <array>
class Game {

private:
	const int rectangleListSize;
	std::array<std::shared_ptr<rectangle>, 9> rectangleList;
	bool graph;

	sf::Color c;
	sf::Color c1;
	std::vector<std::shared_ptr<Command>> commandHistory = {};

	enum class turn {RECTANGLE, CIRCLE};
	turn playerTurn;
	const int win_combinations[8][3] = { {1, 2, 3},
										 {4, 5, 6},
										 {7, 8, 9},
										 {1, 5, 9},
										 {3, 5, 7},
										 {1, 4, 7},
										 {2, 5, 8},
										 {3, 6, 9} };

public:
	Game(bool graph, std::vector< sf::Vector2f> rx);

	void setPlayer();

	void updateScreen(sf::RenderWindow * window);

	std::array<std::shared_ptr<rectangle>, 9>& getRectangleList();

	void action(rectangle * matchedRectangle, bool & done, bool &undo);

	bool checkWin();

};