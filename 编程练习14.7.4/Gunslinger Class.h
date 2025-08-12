#pragma once

#include "Person Class.h"
using PersonClass::Person;

namespace GunslingerClass {
	class Gunslinger : virtual public Person
	{
	public:
		Gunslinger(const string& firstname = "Weihong", const string& lastname = "Ye", const int guncount = 0);
		~Gunslinger();
		double Draw() const;
		virtual void Show() const;
	private:
		int GunCount;
	};

	Gunslinger::Gunslinger(const string& firstname, const string& lastname, const int guncount):Person(firstname, lastname)
	{
		GunCount = guncount;
	}

	Gunslinger::~Gunslinger()
	{
	}

	double Gunslinger::Draw() const
	{
		return static_cast<double>(rand()) / RAND_MAX;
	}

	void Gunslinger::Show() const
	{
		Person::Show();
		cout << "Gun Count: " << GunCount << endl;
		cout << "Draw Time: " << Draw() << endl;
	}
}
