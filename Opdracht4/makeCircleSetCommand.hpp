#ifndef _MAKECIRCLELESETCOMMAND_HPP
#define _MAKECIRCLELESETCOMMAND_HPP

#include <memory>
#include "command.hpp"
#include "rectangle.hpp"

class makeCircleSetCommand : public Command {
private:
	rectangle* r;

public:

	makeCircleSetCommand(rectangle * rec) {
		r = rec;
	}

	void execute() override {
		r->setElement(0);
	}

	int getRecNr() {
		return r->getNumber();
	}

};

#endif
