#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int main()
{
	int i, j, n, lin, col, npc = 0, k = 0, c[20][21];
	float aux, a[20][21], eps=0.000001, piv, s;
	cout << "n= ";
	cin >> n;

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n + 1; j++)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
	cout << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n + 1; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	for (k = 1; k <= n - 1; k++)
	{
		piv = abs(a[k][k]);
		lin = k;
		col = k;
		for (j = k; j <= n; j++)
		{
			for (i = k; i <= n; i++)
			{
				if (piv < abs(a[i][j]))
				{
					piv = abs(a[i][j]);
					lin = i;
					col = j;
				}
			}
		}
		if (piv <= eps)
		{
			cout << "Sistemul nu are solutie unica" << endl;
		}
		if (lin != k)
		{
			for (j = k; j <= n + 1; j++)
			{
				aux = a[k][j];
				a[k][j] = a[lin][j];
				a[lin][j] = aux;
			}
		}
		if (col != k)
		{
			npc = npc + 1;
			c[npc][1] = k;
			c[npc][2] = col;
			for (i = 1; i <= n; i++)
			{
				aux = a[i][k];
				a[i][k] = a[i][col];
				a[i][col] = aux;
			}
		}
		for (i = k + 1; i <= n; i++)
		{
			a[i][k] = a[i][k] / a[k][k];
			for (j = k + 1; j <= n + 1; j++)
			{
				a[i][j] = a[i][j] - a[i][k] * a[k][j];
			}
		}
	}
	if (abs(a[n][n]) <= eps)
	{
		cout << "Sistemul nu are solutie unica" << endl;
	}
	a[n][n + 1] = a[n][n + 1] / a[n][n];
	for (i = n - 1; i >= 1; i--)
	{
		s = 0;
		for (j = i + 1; j <= n; j++)
		{
			s = s + a[i][j] * a[j][n + 1];
		}
		a[i][n + 1] = (a[i][n + 1] - s) / a[i][i];
	}
	if (npc != 0)
	{
		for (i = npc; i >= 1; i--)
		{
			aux = a[c[i][1]][n + 1];
			a[c[i][1]][n + 1] = a[c[i][2]][n + 1];
			a[c[i][2]][n + 1] = aux;
		}
	}
	for (i = 1; i <= n; i++)
	{
		cout << "x" << i << "=" << a[i][n + 1] << endl;
	}
}