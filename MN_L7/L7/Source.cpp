#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n, i, j, k, nr_perm = 0, lin;
	float a[20][20], y[20][20], S, aux, piv;
	// 1.
	cout << "Introduceti dimesiunea matricei patratice: ";
	cin >> n;
	cout << "Introduceti elementele matricei A : " << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << "a[" << i << "]" << "[" << j << "] : ";
			cin >> a[i][j];
		}
		cout << "\n";
	}
	// 2.
	cout << " Introduceti Y^(0) (!=0) : " << endl;
pasul2:for (i = 1; i <= n; i++)
{
	cout << "y[" << i << "] : ";
	cin >> y[i][n];

}

// 3.
for (j = n - 1; j >= 1; j--)
{
	for (i = 1; i <= n; i++)
	{
		y[i][j] = 0;
		for (k = 1; k <= n; k++)
		{
			y[i][j] = y[i][j] + a[i][k] * y[k][j + 1];
		}
	}
}

// 4.
for (i = 1; i <= n; i++)
{
	y[i][n + 1] = 0;
	for (k = 1; k <= n; k++)
	{
		y[i][n + 1] = y[i][n + 1] + a[i][k] * y[k][1];
	}
	y[i][n + 1] = -y[i][n + 1];
}


for (i = 1; i <= n; i++)
{
	cout << "| ";
	for (j = 1; j <= n + 1; j++)
	{
		cout << y[i][j] << "   ";
	}
	cout << " | \n";
}


// Gauss cu pivotare partiala
for (k = 1; k <= n - 1; k++)//
{
	piv = abs(y[k][k]);
	lin = k;
	// cautare pivot 
	for (i = k + 1; i <= n; i++)
	{
		if (piv < abs(y[i][k]))
		{
			piv = abs(y[i][k]);
			lin = i;
		}
	}
	if (piv == 0)
	{
		cout << "Sistemul nu are solutie unica! Introduceti alte valori pentru Y^(0)." << endl;
		goto pasul2;
	}
	if (lin != k)
	{
		// Aici are loc permutarea
		for (j = k; j <= n + 1; j++)
		{
			aux = y[k][j];
			y[k][j] = y[lin][j];
			y[lin][j] = aux;
		}

		nr_perm++;// cerinta
	}

	// aplicarea formulei drept.
	for (i = k + 1; i <= n; i++)
	{
		y[i][k] = y[i][k] / y[k][k];

		for (j = k + 1; j <= n + 1; j++)
		{
			y[i][j] = y[i][j] - (y[i][k] * y[k][j]);
		}
	}

}
cout << "Au avut loc " << nr_perm << " permutari" << endl;// cerinta


if (y[n][n] == 0)
{
	cout << "Sistemul nu are solutie unica!" << endl;
	return 0;
}


y[n][n + 1] = y[n][n + 1] / y[n][n];


for (i = n - 1; i >= 1; i--)
{
	S = 0;
	for (j = i + 1; j <= n; j++)
	{
		S = S + (y[i][j] * y[j][n + 1]);
	}
	y[i][n + 1] = (y[i][n + 1] - S) / y[i][i];
}

cout << endl;
for (i = 1; i <= n; i++)
{
	cout << "c[" << i << "] =" << y[i][n + 1] << endl;
}
return 0;
}