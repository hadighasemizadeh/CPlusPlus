// Undo_Momento.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <memory>

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
	vector<shared_ptr<Memento>> changes; // To store all changes in a vector of shared pointers
	int mIndex;

public:
	explicit BankAccount(const int balance) : balance(balance)
	{
		changes.push_back(make_shared<Memento>(balance)); // Initialize the changes
		int mIndex = 0; // Initialize the Memento index
	}

	shared_ptr<Memento> deposit(const int amount)
	{
		balance += amount;
		auto m = make_shared<Memento>(balance);
		changes.push_back(m);
		mIndex++;
		return m;
	}

	void restore(const shared_ptr<Memento>& m)
	{
		if (m)
		{
			balance = m->balance;
			changes.push_back(m);
			mIndex = changes.size() - 1;
		}
	}

	shared_ptr<Memento> undo()
	{
		if (mIndex>0)
		{
			--mIndex;
			auto m = changes[mIndex];
			balance = m->balance;
			return m;
		}
		return {};
	}

	shared_ptr<Memento> redo()
	{
		if (mIndex + 1 < changes.size())
		{
			++mIndex;
			auto m = changes[mIndex];
			balance = m->balance;
			return m;
		}
		return {};
	}

	friend ostream& operator<< (ostream& os, BankAccount& ba)
	{
		return os << "Balance is " << ba.balance << endl;
	}
};

int main()
{
	BankAccount ba(100); // 100
	cout << ba << endl;

	ba.deposit(100); //200
	cout << ba << endl;

	ba.deposit(50); //250
	cout << ba << endl;

	ba.undo(); //200
	cout << ba << endl;

	ba.undo(); //100
	cout << ba << endl;

	ba.redo(); //200
	cout << ba << endl;

	return 0;
}