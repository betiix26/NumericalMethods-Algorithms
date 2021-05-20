#include<iostream>
#include<math.h>
using namespace std;


int main()
{
	int lin, i, j, n, k, nr_perm = 0;
	float S, piv, a[20][21], aux;
	// 1. Citirea matricei
	cout << "Introduceti dimensiunea matricei patratice : ";
	cin >> n;
	cout << "Introduceti elementele matricei (inclusiv val. term. liberi) : " << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n + 1; j++)
		{
			cout << "a[" << i << "]" << "[" << j << "] : ";
			cin >> a[i][j];
		}
		cout << "\n";
	}

	// 2. Pentru fiecare pivot [k][k] cautam un altul mai mare pe coloana pe care se afla acesta
	for (k = 1; k <= n - 1; k++)//
	{
		piv = abs(a[k][k]);
		lin = k;
		// cautare pivot 
		for (i = k + 1; i <= n; i++)
		{
			if (piv < abs(a[i][k]))
			{
				piv = abs(a[i][k]);
				lin = i;
				cout << "Linia cu indicele " << lin << " a fost permutata." << endl;	// cerinta
				cout << "Valoare pivot [" << i << "," << k << "] : " << piv << endl;// cerinta
			}
		}
		if (piv == 0)
		{
			cout << "Sistemul nu are solutie unica!" << endl;
			return 0;
		}
		if (lin != k)
		{
			// Aici are loc permutarea
			for (j = k; j <= n + 1; j++)
			{
				aux = a[k][j];
				a[k][j] = a[lin][j];
				a[lin][j] = aux;
			}

			nr_perm++;// cerinta
		}

		// aplicarea formulei drept.
		for (i = k + 1; i <= n; i++)
		{
			a[i][k] = a[i][k] / a[k][k];

			for (j = k + 1; j <= n + 1; j++)
			{
				a[i][j] = a[i][j] - (a[i][k] * a[k][j]);
			}
		}

	}
	cout << "Au avut loc " << nr_perm << " permutari" << endl;// cerinta

	// 3.
	if (a[n][n] == 0)
	{
		cout << "Sistemul nu are solutie unica!" << endl;
		return 0;
	}

	// 4.
	a[n][n + 1] = a[n][n + 1] / a[n][n];

	// 5.
	for (i = n - 1; i >= 1; i--)
	{
		S = 0;
		for (j = i + 1; j <= n; j++)
		{
			S = S + (a[i][j] * a[j][n + 1]);
		}
		a[i][n + 1] = (a[i][n + 1] - S) / a[i][i];
	}

	// 6.
	for (i = 1; i <= n; i++)
	{
		cout << "x[" << i << "] =" << a[i][n + 1] << endl;
	}


	return 0;
}