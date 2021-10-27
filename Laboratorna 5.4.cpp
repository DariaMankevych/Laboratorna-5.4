// Laboratorna 5.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Манькевич Дар'я
// Лабораторна робота № 5.4
// Обчислення сум та добутків за допомогою рекурсії
// Варіант 10

#include <iostream>
#include <cmath>
using namespace std;
double P0(const int N)
{
	double n = 1;
	for (int i = N; i <= 16; i++)
		n *= (1.*i * N) / (i * i + N * N);
	return n;
}
double P1(const int N, const int i)
{
	if (i > 16)
		return 0;
	else
		return (1.*i * N) / (i * i + N * N) + P1(N, i + 1);
}
double P2(const int N, const int i)
{
	if (i < N)
		return 0;
	else
		return (1.*i * N) / (i * i + N * N) + P2(N, i - 1);
}
double P3(const int N, const int i, double t)
{
	t = t * (1.*i * N) / (i * i + N * N);
	if (i >= 16)
		return t;
	else
		return P3(N, i + 1, t);
}
double P4(const int N, const int i, double t)
{
	t = t + (1.*i * N) / (i * i + N * N);
	if (i <= 16)
		return t;
	else
		return P4(N, i - 1, t);
}
int main()
{
	int N;
	cout << "N = "; cin >> N;
	cout << "(iter) S0 = " << P0(N) << endl;
	cout << "(rec up ++) S1 = " << P1(N, 16) << endl;
	cout << "(rec up --) S2 = " << P2(N, N) << endl;
	cout << "(rec down ++) S3 = " << P3(N,16, 1) << endl;
	cout << "(rec down --) S4 = " << P4(N, N, 1) << endl;
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
