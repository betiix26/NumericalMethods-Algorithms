#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int i, n;
	float a[20], b[20], c[20], t[20];
	cout << "n= ";
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
	for (i = 1; i <= n - 1; i++)
	{
		cout << "b[" << i << "]=";
		cin >> b[i];
	}
	for (i = 1; i <= n - 1; i++)
	{
        cout << "c[" << i << "]=";
        cin >> c[i];	
	}
	
	for (i = 1; i <= n; i++)
	{
		cout << "t[" << i << "]=";
		cin >> t[i];
	}
	cout << endl;
	

	for (i = 1; i <= n - 1; i++)
	{
		if (a[i] == 0)
		{
			cout << "Sistemul nu are solutie unica deoarece avem elementul diagonal nul in linia " << i;

		}
		c[i] = c[i] / a[i];
		a[i + 1] = a[i + 1] - b[i] * c[i];
	}
	for (i = 2; i <= n; i++)
	{
		t[i] = t[i] - c[i - 1] * t[i - 1];
	}
	if (a[n] == 0)
	{
		cout << "Sistemul nu are solutie unica deoarece avem elementul diagonal nul in linia " << n;
	}
	t[n] = t[n] / a[n];
	for (i = n - 1; i >= 1; i--)
	{
		t[i] = (t[i] - b[i] * t[i + 1]) / a[i];
	}
	for (i = 1; i <= n; i++)
	{
		cout << "x" << i << "=" << t[i] << endl;
	}
}