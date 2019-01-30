// EvenBroker_Mediator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <boost/signals2.hpp>

using namespace boost::signals2;
//using namespace std;

struct Event {
	virtual ~Event() = default;
	virtual void print() const = 0;
};

// An actual event that can happen in the game field
struct PlayerScored : Event
{
	std::string playerName;
	size_t scored_goal_sofar = 0;

	PlayerScored(const std::string& pName, const size_t nog):
		playerName(pName), scored_goal_sofar(nog)
	{
	}

	void print() const override;
};

void PlayerScored::print() const
{
	std::cout << playerName << " has scored their " << scored_goal_sofar << " goal\n";
}

// Event bus/broker
struct Game
{
	signal<void(Event*)> events; // Observer 
};

struct Player {
	std::string name;
	int goal_scored = 0;
	Game& game;

	Player(const std::string& name, Game& game)
		:name(name), game(game)
	{
	}

	void score();
};

void Player::score()
{
	goal_scored++;
	PlayerScored ps(name, goal_scored);
	game.events(&ps); // When player scores he sends an even to the event broker
}

struct Coach
{
	Game& game;

	explicit Coach(Game& g) : game(g)
	{
		// When a coach come to the game he signs up to receive the events
		game.events.connect([](Event* e)
		{
			PlayerScored* ps = dynamic_cast<PlayerScored*>(e);
			if (ps && ps->scored_goal_sofar < 3)
			{
				std::cout << "weldone " << ps->playerName << std::endl;
			}
		});
	}
};

int main()
{
	Game game;
	Player player("Hadi", game);
	Coach coach(game);

	player.score();
	player.score();
	player.score();

	return 0;
}