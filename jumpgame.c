#include <iostream>
#include <cstring>
using namespace std;

int n;
int board[100][100];
int cache[100][100];

int jump(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= n)
		return 0;
	if (x == n - 1 && y == n - 1)
		return 1;
	int& ret = cache[x][y];
	if (ret != -1)
		return ret;
	int jumpsize = board[x][y];
	return ret = (jump(x + jumpsize, y) || jump(x, y + jumpsize));
}

int main(void)
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d", &n);
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				scanf("%d", &board[i][j]);
		}
		if (jump(0, 0))
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
