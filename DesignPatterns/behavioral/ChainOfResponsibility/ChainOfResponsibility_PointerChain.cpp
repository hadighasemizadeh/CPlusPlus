// ChainOfResponsibility_PointerChain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>

class Enemy {
public:
	std::string _name;
	int _attack;
	int _defense;
	// Enemy constructor
	Enemy(const std::string& name, int attack, int defense):_name(name),_attack(attack), _defense(defense)
	{
	}
};

// Insertion operator overload
std::ostream& operator << (std::ostream& o, const Enemy& e)
{
	return o << "Name: " << e._name << " Attack: " << e._attack << " Defense: " << e._defense << std::endl;
}

class EnemyModifier {
private:
	EnemyModifier* next = nullptr; // To store next EnemyModifier after this enemy

protected:
	Enemy& enemy; // To know which enemy we are operating upon

public:
	explicit EnemyModifier(Enemy& enemy):enemy(enemy)
	{
	}
	virtual ~EnemyModifier() = default;

	void add(EnemyModifier* em)
	{
		if (next)	
			next->add(em); //Recursively find last next element that can be set
		else
			next = em;
	}

	virtual void handle()
	{
		if (next) next->handle();
	}
};

class DoubleAttackModifier : public EnemyModifier
{
public:
	explicit DoubleAttackModifier(Enemy& en) : EnemyModifier(en)
	{
	}
	void handle() 
	{
		enemy._attack ++;

		// If don't it => short circuit chain invocation
		// After changing enemy attack all other elements of
		// Chain of responsibility also make modification
		EnemyModifier::handle(); 
	}
};

class IncreaseDefenseModifier : public EnemyModifier
{
public:
	explicit IncreaseDefenseModifier(Enemy& en):EnemyModifier(en)
	{
	}
	void handle() 
	{
		if (enemy._attack <=2)
			enemy._defense ++;

		// Call next element of the change to update
		EnemyModifier::handle();
	}
};

class NoMoreIncrease :public EnemyModifier
{
public:
	explicit NoMoreIncrease(Enemy& enemy):EnemyModifier(enemy)
	{
	}

	// Cuts chain of changes
	void handle()
	{

	}
};
int main()
{
	Enemy Solder{ "Smith", 1, 1 };
	EnemyModifier root{Solder};
	DoubleAttackModifier dba_1{ Solder };
	IncreaseDefenseModifier idm_1{ Solder };
	NoMoreIncrease nmai_1{ Solder };

	//root.add(&nmai_1);
	root.add(&dba_1);
	root.add(&idm_1);
	root.handle(); // Put sequential of changes in action

	std::cout << Solder;

	return 0;
}
