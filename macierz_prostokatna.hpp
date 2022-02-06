#pragma once

#include "macierz.hpp"


using namespace std;


template <typename T = double>
class macierz_prostokatna : public macierz
{
public:
	macierz_prostokatna() // konstruktor domyslny
	{
		h = 0;
		w = 0;
		data = nullptr;
	}
	macierz_prostokatna(int lh, int lw) // konstruktor parametryczny
	{
		h = lh;
		w = lw;
		data = new T*[h]; // alokacja pamieci
		for (int i = 0; i < h; i++)
		{
			data[i] = new T[w];
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
				data[i][j] = 0;
		}
	}
	macierz_prostokatna(const macierz_prostokatna& M) // konstruktor kopiujacy
	{
		h = M.h;
		w = M.w;
		data = new T*[h]; // alokacja pamieci
		for (int i = 0; i < h; i++)
		{
			data[i] = new T[w];
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
				data[i][j] = M.data[i][j];
		}
	}
	~macierz_prostokatna() // destruktor
	{
		for (int i = 0; i < h; i++) // zwolnienie pamieci
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
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
				data[i][j] = d[i][j];
		}
	}
	void print() // drukowanie macierzy
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
				cout << data[i][j] << "\t";
			cout << endl;
		}
		cout << "--------------------------" << endl;
	}
	void read_m() // wczytanie macierzy
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
				cin >> data[i][j];
		}
	}
	macierz_prostokatna<T> operator=(const macierz_prostokatna<T>& M)
	{
		if (h > 0 && w > 0)
		{
			for (int i = 0; i < h; i++) // zwolnienie pamieci
			{
				delete[] data[i];
			}
			delete[] data;
		}
		h = M.h;
		w = M.w;
		data = new T*[h]; // alokacja pamieci
		for (int i = 0; i < h; i++)
		{
			data[i] = new T[w];
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
				data[i][j] = M.data[i][j];
		}
		return *this;
	}
	template <typename T>
	friend macierz_prostokatna<T> operator+(const macierz_prostokatna<T>& a, const macierz_prostokatna<T>& b);
	template <typename T>
	friend macierz_prostokatna<T> operator-(const macierz_prostokatna<T>& a, const macierz_prostokatna<T>& b);
	template <typename T>
	friend macierz_prostokatna<T> operator*(const macierz_prostokatna<T>& a, const macierz_prostokatna<T>& b);
	template <typename T>
	friend macierz_prostokatna<T> operator*(const macierz_prostokatna<T>& a, T val);
private:
	int w; //szerokosc (liczba kolumn)
	int h; //wysokosc (liczba wierszy)
	T** data; // zawartosc macierzy
};

template <typename T>
macierz_prostokatna<T> operator+(const macierz_prostokatna<T>& a, const macierz_prostokatna<T>& b)
{
	if (a.w == b.w && a.h == b.h)
	{
		macierz_prostokatna<T> c(a.h, a.w);
		for (int i = 0; i < a.h; i++)
		{
			for (int j = 0; j < a.w; j++)
				c.data[i][j] = a.data[i][j] + b.data[i][j];
		}
		return c;
	}
	else
		cout << "blad wymiarow" << endl;
	macierz_prostokatna<T> c(0,0);
	return c;
}

template <typename T>
macierz_prostokatna<T> operator-(const macierz_prostokatna<T>& a, const macierz_prostokatna<T>& b)
{
	if (a.w == b.w && a.h == b.h)
	{
		macierz_prostokatna<T> c(a.h, a.w);
		for (int i = 0; i < a.h; i++)
		{
			for (int j = 0; j < a.w; j++)
				c.data[i][j] = a.data[i][j] - b.data[i][j];
		}
		return c;
	}
	else
		cout << "blad wymiarow" << endl;
	macierz_prostokatna<T> c(0, 0);
	return c;
}

template <typename T>
macierz_prostokatna<T> operator*(const macierz_prostokatna<T>& a, T val)
{
	macierz_prostokatna<T> c(a.h,a.w);
	for (int i = 0; i < c.h; i++)
	{
		for (int j = 0; j < c.w; j++)
			c.data[i][j] = val * a.data[i][j];
	}
	return c;
}

template <typename T>
macierz_prostokatna<T> operator*(const macierz_prostokatna<T>& a, const macierz_prostokatna<T>& b)
{
	if (a.w == b.h)
	{
		macierz_prostokatna<T> c(a.h, b.w);
		for (int i = 0; i < c.h; i++)
		{
			for (int j = 0; j < c.w; j++)
			{
				for (int k = 0; k < a.w; k++)
				{
					c.data[i][j] += a.data[i][k] * b.data[k][j];
				}
			}
		}
		return c;
	}
	else
		cout << "blad wymiarow" << endl;
	macierz_prostokatna<T> c(0,0);
	return c;
}