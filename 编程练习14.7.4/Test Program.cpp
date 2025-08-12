#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <cstring>
using std::strchr;
#include "BadDude.h"
using BadDudeClass::BadDude;
using GunslingerClass::Gunslinger;
using PokerPlayerClass::PokerPlayer;
using PersonClass::Person;

const int SIZE = 5;

int main()
{
	Person* lolas[SIZE];
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the person category:\n" << "g:gunslinger p:pokerplayer\n" << "b:baddude q:quit\n";
		cin >> choice;
		while (strchr("gpbq", choice) == NULL)
		{
			cout << "Please enter g, p, b, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice) {
			case 'g':
			lolas[ct] = new Gunslinger;
			break;
			case 'p':
			lolas[ct] = new PokerPlayer;
			break;
			case 'b':
			lolas[ct] = new BadDude;
			break;
		}
		cin.get();
		lolas[ct]->Show();
	}
	cout << "\nHere is your collection:\n";
	for (int i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for (int i = 0; i < ct; i++)
	{
		delete lolas[i];
	}
	cout << "Bye!\n";
	return 0;
}