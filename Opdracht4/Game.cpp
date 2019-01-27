#include "Game.hpp"
#include <iostream>

Game::Game(bool graph, std::vector< sf::Vector2f> rx) :
	graph(graph),
	rectangleListSize(9)
{
	c = sf::Color(150, 0, 0);
	c1 = sf::Color(250, 0, 200);
	for (int i = 0; i < rectangleListSize; i++) {
		rectangleList[i] = std::make_shared<rectangle>(rx[i], c, (i + 1), sf::Vector2f{ 210.0 , 159.0 });
	}
	playerTurn = turn::RECTANGLE;
}

void Game::setPlayer() {
	if (playerTurn == turn::CIRCLE) {
		playerTurn = turn::RECTANGLE;
	}
	else {
		playerTurn = turn::CIRCLE;
	}
}

void Game::updateScreen(sf::RenderWindow * window) {

	if (graph) {
		window->clear();
		for (int i = 0; i < rectangleListSize; i++) {
			rectangleList[i]->draw(*window);
		}
		window->display();
	}
	else {
		for (int i = 0; i < rectangleListSize; i++) {
			std::cout << "|";
			rectangleList[i]->drawText();
			if (i % 3 == 2) {
				std::cout << "|\n";
				std::cout << "------------------------------------------------\n";
			}
		}
	}


}

std::array<std::shared_ptr<rectangle>, 9>& Game::getRectangleList() {
	return rectangleList;
}

void Game::action(rectangle * matchedRectangle, bool & done, bool &undo) {
	if (matchedRectangle) {
		if (!matchedRectangle->isSet()) {
			std::shared_ptr<Command> command;
			if (playerTurn == turn::RECTANGLE) {
				command = std::make_shared<makeRectangleSetCommand>(matchedRectangle);
			}
			else {
				command = std::make_shared<makeCircleSetCommand>(matchedRectangle);
			}
			command->execute();
			setPlayer();
			commandHistory.push_back(command);
			if (checkWin()) {
				std::cout << "you won! \n";
				done = true;
			}
		}

	}
	else {
		std::cout << "no valid input\n";
	}

	if (undo) {
		if (commandHistory.size() > 0) {
			commandHistory.pop_back();
			for (auto & rect : rectangleList) {
				rect->reset();
			}
			for (auto & comm : commandHistory) {
				comm->execute();
			}
			undo = 0;
			setPlayer();
		}
	}

}

bool Game::checkWin() {
	std::vector<int > setPosition1;
	std::vector<int > setPosition2;
	for (unsigned int i = 0; i < commandHistory.size(); i++) {
		if (i % 2 == 0) {
			setPosition1.push_back(commandHistory[i]->getRecNr());
		}
		else {
			setPosition2.push_back(commandHistory[i]->getRecNr());
		}
	}

	for (auto combination : win_combinations) {
		if ((std::find(setPosition1.begin(), setPosition1.end(), combination[0]) != setPosition1.end() &&
			std::find(setPosition1.begin(), setPosition1.end(), combination[1]) != setPosition1.end() &&
			std::find(setPosition1.begin(), setPosition1.end(), combination[2]) != setPosition1.end()))
		{
			return true;
		}
	}
	for (auto combination : win_combinations) {
		if ((std::find(setPosition2.begin(), setPosition2.end(), combination[0]) != setPosition2.end() &&
			std::find(setPosition2.begin(), setPosition2.end(), combination[1]) != setPosition2.end() &&
			std::find(setPosition2.begin(), setPosition2.end(), combination[2]) != setPosition2.end()))
		{
			return true;
		}
	}

	return false;
}