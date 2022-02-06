#pragma once

#include <iostream>

using namespace std;


class macierz
{
public:
	macierz()
	{
		cout << " " << endl;
	}
	virtual ~macierz() = default;
	
	virtual void print() = 0;
};


