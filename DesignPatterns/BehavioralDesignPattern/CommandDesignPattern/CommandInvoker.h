#ifndef COMMANDINVOKER_H
#define COMMANDINVOKER_H
#pragma once

#include "ICommand.h"
#include <iostream>

class CommandInvoker
{
public:
	CommandInvoker();
	~CommandInvoker();
	void Invoke(std::unique_ptr<ICommand> ptr_command);

private:
	std::unique_ptr<ICommand> _ptr_command;
};

#endif //COMMANDINVOKER_H