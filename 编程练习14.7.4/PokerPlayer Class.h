#pragma once

#include "Person Class.h"
using PersonClass::Person;

namespace PokerPlayerClass {
	class PokerPlayer : virtual public Person
	{
	public:
		PokerPlayer(const string& firstname = "Weihong", const string& lastname = "Ye");
		~PokerPlayer();
		int Draw() const { return rand() % 52; }
		virtual void Show() const;
	private:

	};

	PokerPlayer::PokerPlayer(const string& firstname, const string& lastname) :Person(firstname, lastname)
	{
	}

	PokerPlayer::~PokerPlayer()
	{
	}

	void PokerPlayer::Show() const
	{
		Person::Show();
		cout << "Drawn Card: " << Draw() << endl;
	}
}
