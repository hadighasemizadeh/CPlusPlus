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

class Command
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
	void call() const
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

int main()
{
	BankAcount ba;
	vector<Command> commands {
		Command (ba,Command::deposit, 100 ),
		Command (ba,Command::withdraw, 200)
	};

	for (auto cmd:commands)
	{
		cmd.call();
	}
	return 0;
}