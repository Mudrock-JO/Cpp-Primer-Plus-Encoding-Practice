#pragma once

#include <iostream>

namespace PairClass
{
	template <typename T1, typename T2>
	class Pair
	{
	public:
		Pair(const T1& aval, const T2& bval) :a(aval), b(bval) {}
		Pair() {}
		T1 first() const { return a; }
		T2 second() const { return b; }
		T1& first();
		T2& second();
	private:
		T1 a;
		T2 b;
	};

	template <typename T1, typename T2>
	T1& Pair<T1, T2>::first()
	{
		return a;
	}

	template <typename T1, typename T2>
	T2& Pair<T1, T2>::second()
	{
		return b;
	}
}
