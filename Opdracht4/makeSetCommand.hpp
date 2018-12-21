#ifndef _MAKESETCOMMAND_HPP
#define _MAKESETCOMMAND_HPP

#include "command.hpp"
#include "rectangle.hpp"

class makeSetCommand : public Command {

public: 

	makeSetCommand() {}

	void execute(rectangle * r, int set) override {
		r->setElement(set);
	}

};

#endif
