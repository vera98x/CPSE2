#include "command.hpp"
#include "rectangle.hpp"

class makeSetCommand : public Command {

public: 

	makeSetCommand() {}

	void execute(rectangle * r, int set) override {
		r->setElement(set);
	}
};
