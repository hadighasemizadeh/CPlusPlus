#ifndef ExecuteExtractionCommand_H
#define ExecuteExtractionCommand_H
#pragma once

#include "ICommand.h"
#include <iostream>

class ExecuteExtractionCommand : public ICommand
{
public:
	ExecuteExtractionCommand();
	~ExecuteExtractionCommand();
	void Execute() override;

};

#endif // !ExecuteExtractionCommand_H
