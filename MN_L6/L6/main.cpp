	#include<iostream>
	#include<stdlib.h>
	#include<math.h>
	using namespace std;

	float g(float x)
	{
		return 4./sqrt(x+3);
	}

	int main()
	{

	int itmax, it;
	float x0, x1, eps, dif;

	cout << "itmax = ";
	cin >> itmax;

	cout << "eps = ";
	cin >> eps;

	cout << "x0 = ";
	cin >> x0;

	it = 0;

	do {
		x1 = g(x0);
		dif = fabs(x1 - x0);
		x0 = x1;
	it++;
	} while (!((dif <= eps) || (it > itmax)));

	if (it > itmax)
	{
		cout << "Nu se poate obtine solutia in " << itmax << " iteratii, cu precizia " << eps;
		return 0;
	}

	cout << "Solutia obtinuta in " << it << " iteratii cu precizia " << eps << " este " << x1;

	return 0;
	}