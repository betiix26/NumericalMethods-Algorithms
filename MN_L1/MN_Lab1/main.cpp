#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int i, j, n;
	float a[20][21];
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
	int k;
	for (k = 1; k <= n - 1; k++)
	{
		if (a[k][k] != 0)
		{
			for (i = k + 1; i <= n; i++)
			{
				a[i][k] = a[i][k] / a[k][k];

				for (j = k + 1; j<=n+1;j++)
				{
					a[i][j] = a[i][j] - a[i][k] * a[k][j];
				}
			}
		}
		else return 0;
	}
	if (a[n][n] == 0)
	{
		cout << "Sistemul nu are solutie unica";
	}
	

	a[n][n + 1] = a[n][n + 1] / a[n][n];
	float s;
	for (i = n - 1; i >= 1; i--)
	{
		s = 0;
		for (j = i + 1; j<=n; j++) 
		{
			s = s + a[i][j] * a[j][n + 1];
		}
		a[i][n + 1] = (a[i][n + 1] - s) / a[i][i];
	}

	for (i = 1; i <= n; i++)
	{
		cout << "x" << i <<"=" << a[i][n + 1] << endl;
	}
	
}
	
		
