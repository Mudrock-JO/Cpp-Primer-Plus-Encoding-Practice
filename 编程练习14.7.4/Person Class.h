#pragma once

#include<string>
using std::string;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

namespace PersonClass {
	class Person
	{
	public:
		Person(const string& firstname = "Weihong", const string& lastname = "Ye");
		~Person();
		virtual void Show() const = 0;
	private:
		string FirstName;
		string LastName;
	};

	Person::Person(const string& firstname, const string& lastname)
	{
		FirstName = firstname;
		LastName = lastname;
	}

	Person::~Person()
	{
	}

	void Person::Show() const
	{
		cout << "First Name: " << FirstName << endl;
		cout << "Last Name: " << LastName << endl;
	}
}
