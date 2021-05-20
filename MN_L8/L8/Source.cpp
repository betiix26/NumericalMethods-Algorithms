#include<iostream>

using namespace std;


int main()
{
	int i, j, n, k, h;
	float a[10][10], b[10][10], d[10][10], c[10];

	// 1.citeste n, aij , 1 <= i, j <= n
	cout << " Introduceti dimeniunea matricei A: ";
	cin >> n;
	cout << "Introduceti elementele matricei A :" << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << "a[" << i << "]" << "[" << j << "] : ";
			cin >> a[i][j];
		}
		cout << "\n";
	}

	// 2. initializam B cu matricea unitate In
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				b[i][j] = 1;
			}
			else
				b[i][j] = 0;
		}
	}

	// 3.
	for (k = 1; k <= n - 1; k++)
	{
		// calculam A[k], folosind A[k] = A * B[k-1], si notam D= A[k]
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				d[i][j] = 0;
				for (h = 1; h <= n; h++)
				{
					d[i][j] = d[i][j] + a[i][h] * b[h][j];
				}
			}
		}
		// calculam C[k], folosind C[k] = - Tr(A[k])/k
		c[k] = 0;
		for (i = 1; i <= n; i++)
		{
			c[k] = c[k] + d[i][i];
		}
		c[k] = -c[k] / k;

		// calculam B[k], folosind B[k] = C[k]*In + A[k]
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (i == j)
				{
					b[i][j] = d[i][j] + c[k];
				}
				else
					b[i][j] = d[i][j];
			}
		}
	}

	// 4. Calculam An = D
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			d[i][j] = 0;
			for (h = 1; h <= n; h++)
			{
				d[i][j] = d[i][j] + a[i][h] * b[h][j];
			}
		}
	}
	// 5.
	c[n] = 0;

	// 6.
	for (i = 1; i <= n; i++)
	{
		c[n] = c[n] + d[i][i];
	}

	// 7.
	c[n] = -c[n] / n;

	// 8.
	if (c[n] == 0)
	{
		cout << "Matricea nu este inversabila." << endl;
	}
	else
	{
		cout << "Matricea inversabila este: " << endl;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				cout << -b[i][j] / c[n] << "  ";
			}
			cout << endl;
		}
	}
	// 9.
	cout << "Coeficientii polinomului caracteristic sunt: " << endl;
	for (i = 1; i <= n; i++)
	{
		cout << c[i] << "   ";
	}
	return 0;
}