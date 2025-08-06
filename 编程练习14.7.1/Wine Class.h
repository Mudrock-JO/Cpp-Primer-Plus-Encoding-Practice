#pragma once

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <valarray>
using std::valarray;
#include "Pair Class.h"

namespace WineClass {
	class Wine
	{
	public:
		Wine(const char* l, int y, const int yr[], const int bot[]);
		Wine(const char* l, int y);
		Wine();
		~Wine();
		void GetBottles();
		const string& Label() const { return Name; }
		int Sum() const;
		void Show() const;
	private:
		string Name;
		PairClass::Pair<valarray<int>, valarray<int>> YearAndBottles;
		int Years;
	};

	Wine::Wine()
	{
	}

	Wine::~Wine()
	{
	}

	Wine::Wine(const char* l, int y, const int yr[], const int bot[])
	{
		Name = l;
		Years = y;
		YearAndBottles = PairClass::Pair<valarray<int>, valarray<int>>(valarray<int>(yr,Years), valarray<int>(bot,Years));
	}

	Wine::Wine(const char* l, int y)
	{
		Name = l;
		Years = y;
	}

	void Wine::GetBottles()
	{
		int* yr = new int[Years];
		int* bot = new int[Years];
		cout << "Enter " << Name << " data for " << Years << " year(s):" << endl;
		for (int i = 0;i < Years;i++)
		{
			cout << "Enter year: ";
			cin >> yr[i];
			cout << "Enter bottles for that year: ";
			cin >> bot[i];
		}
		YearAndBottles = PairClass::Pair<valarray<int>, valarray<int>>(valarray<int>(yr, Years), valarray<int>(bot, Years));
	}

	int Wine::Sum() const
	{
		return YearAndBottles.second().sum();
	}

	void Wine::Show() const
	{
		cout << "Wine: " << Name << endl;
		cout << "\tYears\tBottles" << endl;
		for (int i = 0;i < Years;i++)
		{
			cout << "\t" << YearAndBottles.first()[i] << "\t" << YearAndBottles.second()[i] << endl;
		}
	}
}