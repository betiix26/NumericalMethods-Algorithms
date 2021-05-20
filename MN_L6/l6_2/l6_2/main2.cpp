#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int i, n, j;
	float a[20][20], b[20], x[20], s, y[20], it, max, eps, itmax;
	cout << "n= ";
	cin >> n;
	cout << "eps = ";
	cin >> eps;
	cout << "itmax = ";
	cin >> itmax;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
	cout << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	for (i = 1; i <= n; i++)
	{
		cout << "b[" << i << "]=";
		cin >> b[i];
	}
	cout << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "x[" << i << "]=";
		cin >> x[i];
	}
	cout << endl;

	it = 0;
	do
	{
		max = 0;
		for (i = 1; i <= n; i++)
		{

			s = 0;
			for (j = 1; j <= n; j++)
			{

				if (j != i)
				{
					s = s + a[i][j] * x[j];
				}
			}
			y[i] = (b[i] - s) / a[i][i];
			if (max < fabs(y[i] - x[i]))
			{
				max = fabs(y[i] - x[i]);
			}
			x[i] = y[i];
		}
		it = it + 1;
	} while (!((max <= eps) || (it > itmax)));

	if (it > itmax)
	{
		cout << "Nu se poate obtine solutia in " << itmax << " iteratii, cu precizia " << eps;
		cout << endl;
	}

	for (i = 1; i <= n; i++)
	{
		cout << "Solutia obtinuta in " << it << " iteratii cu precizia " << eps << " este " << x[i] << endl;
	}
}

