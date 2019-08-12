// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "ICommand.h"
#include "CommandInvoker.h"
#include "ExecuteExtractionCommand.h"
#include "StartExtractionCommand.h"

#include "CommandInvoker.h"

#include <iostream>
#include <memory>


int main()
{
	CommandInvoker cmdInvoker;
	cmdInvoker.Invoke(std::unique_ptr<ICommand>(new ExecuteExtractionCommand()));
	cmdInvoker.Invoke(std::unique_ptr<ICommand>(new StartExtractionCommand()));
}