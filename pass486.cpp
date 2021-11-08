#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int TM = 1000 * 1000 * 10;

int factors[TM + 1];

void getFactorsBrute()
{
	memset(factors, 0, sizeof(factors));
	for (int div = 1; div <= TM; ++div)
	{
		for (int multiple = div; multiple <= TM; multiple += div)
			factors[multiple] += 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	getFactorsBrute();
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, lo, hi;
		cin >> n >> lo >> hi;
		int ans = 0;
		for (int i = lo; i <= hi; i++)
		{
			if (factors[i] == n)
				ans++;
		}
		cout << ans << "\n";
	}
	
	return 0;
}
