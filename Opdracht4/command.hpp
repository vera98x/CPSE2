#ifndef _COMMAND_HPP
#define _COMMAND_HPP

class Command {
public:
	virtual void execute() = 0;
	virtual int getRecNr() = 0;
};

#endif
