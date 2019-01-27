// Command.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

class BankAcount
{
public:
	int balance = 0;
	int overdraft_limit = -200;

	void deposit(int amount)
	{
		balance += amount;
		std::cout << "deposited: " << amount << " ,balance now " << balance << "\n";
	}

	void withdraw(int amount)
	{
		if (balance-amount>=overdraft_limit)
		{
			balance -= amount;
			std::cout << "withdraw: " << amount << " ,balance now " << balance << "\n";
		}
	}
	friend ostream& operator << (ostream os, BankAcount& ba)
	{
		return os << "Ballance is" << ba.balance << endl;
	}
};

// Interface
class ICommand
{
public:
	virtual ~ICommand() = default;
	virtual void call() const = 0;
};

class Command : ICommand
{
public:
	BankAcount& account; // Reference to bank account that we are operating upon
	enum Action {deposit, withdraw} action; // Action list that can be done on bank account
	int amount;
	Command(BankAcount& ac, const Action action, const int amount)
			:account(ac),action(action),amount(amount)
	{
	}

	// States of actions
	void call() const override 
	{
		switch (action)
		{
			case Command::deposit:
				account.deposit(amount);
				break;
			case Command::withdraw:
				account.withdraw(amount);
				break;
			default:
				break;
		}
	}
};

class CommandList : vector<Command> , ICommand
{
public:
	CommandList(const initializer_list<Command>& _IList) : vector<Command>(_IList)
	{
	}

	void call() const override
	{
		for (auto& cmd : *this)
		{
			cmd.call();
		}
	}
};

int main()
{
	BankAcount ba;
	CommandList commands {
		Command (ba,Command::deposit, 100 ),
		Command (ba,Command::withdraw, 200)
	};

	commands.call();

	return 0;
}