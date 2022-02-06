#pragma once

#include "macierz.hpp"


using namespace std;


template <typename T = double>
class macierz_kwadratowa : public macierz
{
public:
	macierz_kwadratowa() // konstruktor domyslny
	{
		n = 0;
		data = nullptr;
	}
	macierz_kwadratowa(int r) // konstruktor parametryczny
	{
		n = r;
		data = new T*[n]; // alokacja pamieci
		for (int i = 0; i < n; i++)
		{
			data[i] = new T[n];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				data[i][j] = 0;
		}
	}
	macierz_kwadratowa(const macierz_kwadratowa& M) // konstruktor kopiujacy
	{
		n = M.n;
		data = new T * [n]; // alokacja pamieci
		for (int i = 0; i < n; i++)
		{
		data[i] = new T[n];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				data[i][j] = M.data[i][j];
		}
	}
	~macierz_kwadratowa() // destruktor
	{
		for (int i = 0; i < n; i++) // zwolnienie pamieci
		{
			delete[] data[i];
		}
		delete[] data;
	}
	void set_value(int i, int j, T val) // ustawienie wartosci
	{
		data[i][j] = val;
	}
	void set_data(T** d) // ustawienie zawartosci
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				data[i][j] = d[i][j];
		}
	}
	void print() // drukowanie macierzy
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << data[i][j] << "\t";
			cout << endl;
		}
		cout << "--------------------------" << endl;
	}
	void read_m() // wczytanie macierzy
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> data[i][j];
		}
	}
	macierz_kwadratowa<T> operator=(const macierz_kwadratowa<T>& M)
	{
		if (n > 0)
		{
			for (int i = 0; i < n; i++) // zwolnienie pamieci
			{
				delete[] data[i];
			}
			delete[] data;
		}
		n = M.n;
		data = new T * [n]; // alokacja pamieci
		for (int i = 0; i < n; i++)
		{
			data[i] = new T[n];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				data[i][j] = M.data[i][j];
		}
		return *this;
	}
	template <typename T>
	friend macierz_kwadratowa<T> operator+(const macierz_kwadratowa<T>& a, const macierz_kwadratowa<T>& b);
	template <typename T>
	friend macierz_kwadratowa<T> operator-(const macierz_kwadratowa<T>& a, const macierz_kwadratowa<T>& b);
	template <typename T>
	friend macierz_kwadratowa<T> operator*(const macierz_kwadratowa<T>& a, const macierz_kwadratowa<T>& b);
	template <typename T>
	friend macierz_kwadratowa<T> operator*(const macierz_kwadratowa<T>& a, T val);
private:
	int n; //liczba wierszy i kolumn
	T** data; // zawartosc macierzy
};

template <typename T>
macierz_kwadratowa<T> operator+(const macierz_kwadratowa<T>& a, const macierz_kwadratowa<T>& b)
{
	if (a.n == b.n)
	{
		macierz_kwadratowa<T> c(a.n);
		for (int i = 0; i < a.n; i++)
		{
			for (int j = 0; j < a.n; j++)
				c.data[i][j] = a.data[i][j] + b.data[i][j];
		}
		return c;
	}
	else
		cout << "blad wymiarow" << endl;
		macierz_kwadratowa<T> c(0);
		return c;
}

template <typename T>
macierz_kwadratowa<T> operator-(const macierz_kwadratowa<T>& a, const macierz_kwadratowa<T>& b)
{
	if (a.n == b.n)
	{
		macierz_kwadratowa<T> c(a.n);
		for (int i = 0; i < c.n; i++)
		{
			for (int j = 0; j < c.n; j++)
				c.data[i][j] = a.data[i][j] - b.data[i][j];
		}
		return c;
	}
	else
		cout << "blad wymiarow" << endl;
		macierz_kwadratowa<T> c(0);
		return c;
}

template <typename T>
macierz_kwadratowa<T> operator*(const macierz_kwadratowa<T>& a, T val)
{
	macierz_kwadratowa<T> c(a.n);
	for (int i = 0; i < c.n; i++)
	{
		for (int j = 0; j < c.n; j++)
			c.data[i][j] = val * a.data[i][j];
	}
	return c;
}

template <typename T>
macierz_kwadratowa<T> operator*(const macierz_kwadratowa<T>& a, const macierz_kwadratowa<T>& b)
{
	if (a.n == b.n)
	{

		macierz_kwadratowa<T> c(a.n);
		for (int i = 0; i < c.n; i++)
		{
			for (int k = 0; k < c.n; k++)
			{
				for (int j = 0; j < c.n; j++)
				{
					c.data[i][j] += a.data[i][k] * b.data[k][j];
				}
			}
		}
		return c;
	}
	else
		cout << "blad wymiarow" << endl;
		macierz_kwadratowa<T> c(0);
		return c;
}

