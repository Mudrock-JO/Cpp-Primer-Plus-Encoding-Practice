#pragma once

#include "PokerPlayer Class.h"
using PokerPlayerClass::PokerPlayer;
#include "Gunslinger Class.h"
using GunslingerClass::Gunslinger;

namespace BadDudeClass
{
	class BadDude : public PokerPlayer, public Gunslinger
	{
	public:
		BadDude(const string& firstname = "Weihong", const string& lastname = "Ye", const int guncount = 0);
		~BadDude();
		double Gdraw() const { return Gunslinger::Draw(); }
		int Cdraw() const { return PokerPlayer::Draw(); }
		virtual void Show() const;
	private:

	};

	BadDude::BadDude(const string& firstname, const string& lastname, const int guncount): PokerPlayer(firstname, lastname), Gunslinger(firstname, lastname, guncount), Person(firstname, lastname)
	{
	}

	BadDude::~BadDude()
	{
	}

	void BadDude::Show() const
	{
		Gunslinger::Show();
		cout << "Drawn Card: " << PokerPlayer::Draw() << endl;
		cout << "Gdraw: " << Gdraw() << endl;
		cout << "Cdraw: " << Cdraw() << endl;
	}
}
