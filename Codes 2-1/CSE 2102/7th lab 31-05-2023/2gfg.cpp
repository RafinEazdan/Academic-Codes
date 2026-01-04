#include <bits/stdc++.h>
using namespace std;

bool checkcomposite(int n)
{
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return 1;
	}
	return 0;
}

int power(int x, int y, int mod)
{

	int res = 1;

	while (y) {
		if (y & 1)
			res = (res * x) % mod;

		y = y >> 1;
		x = (x * x) % mod;
	}
	return res;
}
bool Check(int n, int a)
{
	if (a>1 && checkcomposite(n) && power(a, n - 1, n) == 1)
		return 1;

	return 0;
}

int main()
{

	int N = 340;
	int a = 2;
	cout << Check(N, a);

	return 0;
}
