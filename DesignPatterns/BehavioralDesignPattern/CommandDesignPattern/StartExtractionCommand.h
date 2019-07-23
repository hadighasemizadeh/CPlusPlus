#ifndef StartExtractionCommand_H
#define StartExtractionCommand_H
#pragma once

#include "ICommand.h"
#include <iostream>

class StartExtractionCommand : public ICommand
{
public:
	StartExtractionCommand();
	~StartExtractionCommand();
	void Execute() override;
};
#endif //!StartExtractionCommand_H
