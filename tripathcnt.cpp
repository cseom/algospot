#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MOD = 1000000007;

int n;
int cache[101][101];
int countCache[101][101];
int triangle[101][101];

int path(int x, int y)
{
	if (x == n - 1)
		return triangle[x][y];
	int& ret = cache[x][y];
	if (ret != -1)
		return ret;
	return ret = max(path(x + 1, y), path(x + 1, y + 1)) + triangle[x][y];
}

int count(int x, int y)
{
	if (x == n - 1)
		return 1;
	int& ret = countCache[x][y];
	if (ret != -1)
		return ret;
	ret = 0;
	if (path(x + 1, y + 1) >= path(x + 1, y))
		ret += count(x + 1, y + 1);
	if (path(x + 1, y + 1) <= path(x + 1, y))
		ret += count(x + 1, y);
	return ret;
}

int main(void)
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		memset(countCache, -1, sizeof(cache));
		memset(cache, -1, sizeof(cache));
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
				cin >> triangle[i][j];
		}
		cout << count(0, 0) << "\n";
	}
}
