#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MOD = 1000000007;

int cache[101];

int tiling(int width)
{
	if (width <= 1)
		return 1;
	int& ret = cache[width];
	if (ret != -1)
		return ret;
	return ret = (tiling(width - 1) + tiling(width - 2)) % MOD;
}

int main(void)
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		memset(cache, -1, sizeof(cache));
		cin >> n;
		cout << tiling(n) << "\n";
	}
}
