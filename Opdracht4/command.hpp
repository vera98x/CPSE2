#ifndef _COMMAND_HPP
#define _COMMAND_HPP

class Command {
public:
	virtual void execute(rectangle * r, int set) = 0;
};

#endif
