#include <iostream>
#include <cstring>
using namespace std;

int h, w;
const int coverType[4][3][2] =
{
{{0, 0}, {1, 0}, {0, 1}},
{{0, 0}, {1, 0}, {1, 1}},
{{0, 0}, {0, 1}, {1, 1}},
{{0, 0}, {1, 0}, {1, -1}}
};
char board[20][20];
int  intboard[20][20];

bool set(int x, int y, int type, int delta)
{
	bool ok = true;
	for (int i = 0; i < 3; i++)
	{
		int nx = x + coverType[type][i][0];
		int ny = y + coverType[type][i][1];
		if (nx < 0 || nx >= h || ny < 0 || ny >= w)
			ok = false;
		else if ((intboard[nx][ny] += delta) > 1)
			ok = false;
	}
	return ok;
}

int cover()
{
	int x = -1;
	int y = -1;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (intboard[i][j] == 0)
			{
				x = i;
				y = j;
				break;
			}
		}
		if (y != -1)
			break;
	}
	if (y == -1)
		return 1;
	int ret = 0;
	for (int type = 0; type < 4; type++)
	{
		if (set(x, y, type, 1))
			ret += cover();
		set(x, y, type, -1);
	}
	return ret;
}

int main(void)
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d %d", &h, &w);
		//memset(intboard, 0, sizeof(intboard));
		for (int i = 0; i < h; i++)
			scanf("%s", board[i]);
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (board[i][j] == '#')
					intboard[i][j] = 1;
				else
					intboard[i][j] = 0;
			}
		}
		printf("%d\n", cover());
	}
	return 0;
}
