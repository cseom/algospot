#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, d, p, t, q;
int connected[51][51];
double cache[51][101];
int deg[51];

/*
double search(vector<int> &path)
{
	if (path.size() == d + 1)
	{
		if (path.back() != q)
			return 0.0;
		double ret = 1.0;
		for (int i = 0; i + 1 < path.size(); i++)
			ret /= deg[path[i]];
		return ret;
	}
	double ret = 0;
	for (int there = 0; there < n; there++)
	{
		if (connected[path.back()][there])
		{
			path.push_back(there);
			ret += search(path);
			path.pop_back();
		}
	}
	return ret;
}
*/

double search(int here, int days)
{
	if (days == 0)
		return (here == p ? 1.0 : 0.0);
	double& ret = cache[here][days];
	if (ret > -0.5)
		return ret;
	ret = 0.0;
	for (int there = 0; there < n; there++)
	{
		if (connected[here][there])
			ret += search(there, days - 1) / deg[there];
	}
	return ret;
}

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{

		memset(deg, 0, sizeof(deg));
		scanf("%d %d %d", &n, &d, &p);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &connected[i][j]);
				if (connected[i][j])
					deg[i] += 1;
			}
		}
		scanf("%d", &t);
		for (int i = 0; i < t; i++)
		{
			for (int i = 0; i < 51; i++)
			{
				for (int j = 0; j < 101; j++)
					cache[i][j] = -0.5;
			}
			scanf("%d", &q);
			printf("%.8lf ", search(q, d));
		}
		printf("\n");
	}

	return 0;
}


