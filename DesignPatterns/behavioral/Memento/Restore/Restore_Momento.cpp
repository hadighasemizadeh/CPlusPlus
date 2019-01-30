// Undo_Momento.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

class Memento
{
	int balance = 0;
public:
	Memento(const int balance) : balance(balance)
	{
	}

	friend class BankAccount; // To be able to pass balance to BankAccount class
};

class BankAccount
{
	int balance = 0;
public:
	BankAccount(const int balance) : balance(balance)
	{
	}

	Memento deposit(const int amount)
	{
		balance += amount;
		return { balance };
	}

	void restore(const Memento& mem)
	{
		balance = mem.balance;
	}

	friend ostream& operator<< (ostream& os, BankAccount& ba)
	{
		return os << "Balance is " << ba.balance << endl;
	}
};

int main()
{
	BankAccount ba(100);
	auto m1 = ba.deposit(50);
	auto m2 = ba.deposit(200);

	cout << ba << endl;

	ba.restore(m1);
	cout << ba << endl;

	ba.restore(m2);
	cout << ba << endl;

	return 0;
}