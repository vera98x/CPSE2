#ifndef _MAKERECTANGLESETCOMMAND_HPP
#define _MAKERECTANGLESETCOMMAND_HPP

#include <memory>
#include "command.hpp"
#include "rectangle.hpp"

class makeRectangleSetCommand : public Command {
private:
	rectangle* r;

public:

	makeRectangleSetCommand(rectangle * rec) {
		r = rec;
	}

	void execute() override {
		r->setElement(1);
	}

	int getRecNr() {
		return r->getNumber();
	}

};

#endif
