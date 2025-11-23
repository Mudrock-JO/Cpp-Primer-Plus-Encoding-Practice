#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "Pair Class.h"
#include <valarray>
using std::valarray;
#include <string>
using std::string;

namespace WineClass {
	class Wine :private string, private PairClass::Pair<valarray<int>, valarray<int>>
	{
	public:
		Wine(const char* l, int y, const int yr[], const int bot[]);
		Wine(const char* l, int y);
		Wine();
		~Wine();
		void GetBottles();
		const string& Label() const { return (const string&)*this; };
		int Sum() const;
		void Show() const;
	private:
		int Years;
	};

	Wine::Wine()
	{
	}

	Wine::~Wine()
	{
	}

	Wine::Wine(const char* l, int y, const int yr[], const int bot[]) : string(l), PairClass::Pair<valarray<int>, valarray<int>>(valarray<int>(yr, y), valarray<int>(bot, y))
	{
		Years = y;
	}

	Wine::Wine(const char* l, int y) : string(l)
	{
		Years = y;
	}

	void Wine::GetBottles()
	{
		int* yr = new int[Years];
		int* bot = new int[Years];
		cout << "Enter " << (const string&) *this<< " data for " << Years << " year(s):" << endl;
		for (int i = 0;i < Years;i++)
		{
			cout << "Enter year: ";
			cin >> yr[i];
			cout << "Enter bottles for that year: ";
			cin >> bot[i];
		}
		(PairClass::Pair<valarray<int>, valarray<int>>) *this= PairClass::Pair<valarray<int>, valarray<int>>(valarray<int>(yr, Years), valarray<int>(bot, Years));
	}

	int Wine::Sum() const
	{
		return ((const PairClass::Pair<valarray<int>, valarray<int>>&) *this).second().sum();
	}

	void Wine::Show() const
	{
		cout << "Wine: " << (const string&)*this << endl;
		cout << "\tYears\tBottles" << endl;
		for (int i = 0;i < Years;i++)
		{
			cout << "\t" << ((const PairClass::Pair<valarray<int>, valarray<int>>&) * this).first()[i] << "\t" << ((const PairClass::Pair<valarray<int>, valarray<int>>&) * this).second()[i] << endl;
		}
	}
}
