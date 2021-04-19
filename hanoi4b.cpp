#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_DICS = 12;

int get(int state, int index)
{
	return (state >> (index * 2)) & 3;
}

int set(int state, int index, int value)
{
	return (state & ~(3 << (index * 2))) | (value << (index * 2));
}

int sgn(int x)
{
	if (!x)
		return 0;
	return x > 0 ? 1 : -1;
}

int incr(int x)
{
	if (x < 0)
		return x - 1;
	return x + 1;
}

int c[1 << (MAX_DICS * 2)];

int bfs(int discs, int begin, int end)
{
	if (begin == end)
		return 0;
	queue<int> q;
	memset(c, 0, sizeof(c));
	q.push(begin);
	c[begin] = 1;
	q.push(end);
	c[end] = -1;
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		int top[4] = { -1, -1, -1, -1 };
		for (int i = discs - 1; i >= 0; i--)
			top[get(here, i)] = i;
		for (int i = 0; i < 4; i++)
		{
			if (top[i] != -1)
			{
				for (int j = 0; j < 4; j++)
				{
					if (i != j && (top[j] == -1 || top[j] > top[i]))
					{
						int there = set(here, top[i], j);
						if (c[there] == 0)
						{
							c[there] = incr(c[here]);
							q.push(there);
						}
						else if (sgn(c[there]) != sgn(c[here]))
							return abs(c[there]) + abs(c[here]) - 1;
					}
				}
			}
		}
	}
	return -1;
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		int cnt = 0;
		int begin = 0;
		int end = 0;
		for (int i = 0; i < 4; i++)
		{
			int k;
			cin >> k;
			for (int j = 0; j < k; j++)
			{
				int x;
				cin >> x;
				begin = set(begin, x - 1, i);
				end = set(end, cnt++, 3);
			}
		}
		cout << bfs(n, begin, end) << '\n';
	}
	return 0;
}
