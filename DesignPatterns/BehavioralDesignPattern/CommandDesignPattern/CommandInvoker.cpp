#include "pch.h"
#include "CommandInvoker.h"


CommandInvoker::CommandInvoker()
{
}


CommandInvoker::~CommandInvoker()
{
}

void CommandInvoker::Invoke(std::unique_ptr<ICommand> ptr_command)
{
	if (nullptr == ptr_command)
	{
		std::cout << "Error: Pointer was empty!!\n";
		return;
	}

	_ptr_command = std::move(ptr_command);
	_ptr_command->Execute();
}
