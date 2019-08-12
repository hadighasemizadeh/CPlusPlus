// MediatorDesignPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "ICommand.h"
#include "CommandInvoker.h"
#include "ExecuteExtractionCommand.h"
#include "StartExtractionCommand.h"

#include <iostream>
#include <memory>

int main()
{
    std::cout << "Mediator!\n"; 
	CommandInvoker cmdInvoker;
	cmdInvoker.Invoke(std::unique_ptr<ICommand>(new ExecuteExtractionCommand()));
	cmdInvoker.Invoke(std::unique_ptr<ICommand>(new StartExtractionCommand()));
}