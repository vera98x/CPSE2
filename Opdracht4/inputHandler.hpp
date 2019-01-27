#ifndef _INPUTHANDLER_HPP
#define _INPUTHANDLER_HPP

#include "command.hpp"
#include "rectangle.hpp"
#include <vector>
#include <array>

class inputHandler {
private:

public:

	inputHandler();


	sf::Vector2f Vector2f_from_Vector2i(const sf::Vector2i & rhs);

	rectangle* handleInput(const std::array<std::shared_ptr<rectangle>, 9> & rectangleList, bool graph, sf::RenderWindow * window, bool &undo);

};


#endif // !_INPUTHANDLER_HPP
