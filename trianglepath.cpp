#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_NUMBER = 100000;

int n;
int triangle[100][100];
int cache[100][100];

int path(int x, int y)
{
	if (x == n - 1)
		return (triangle[x][y]);
	int& ret = cache[x][y];
	if (ret != -1)
		return ret;
	return ret = max(path(x + 1, y), path(x + 1, y + 1)) + triangle[x][y];
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n;
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
				cin >> triangle[i][j];
		}
		cout << path(0, 0) << "\n";
	}
	return 0;
}
