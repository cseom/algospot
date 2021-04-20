#include <iostream>
#include <vector>
#include <queue>
#include <cfloat>
#include <limits>
using namespace std;

int n;
vector<vector<pair<int, double>>> adj;

double dijkstra()
{
	vector<double> dist(n + 1, DBL_MAX);
	dist[0] = 1.0;

	priority_queue<pair<double , int>> pq;
	pq.push(make_pair(-1.0, 0));

	while (!pq.empty())
	{
		double cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost)
			continue;

		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			double nextDist = cost * adj[here][i].second;
			if (dist[there] > nextDist)
			{
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist[n - 1];
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int m;
		cin >> n >> m;
		adj.clear();
		adj.resize(n + 1);
		for (int i = 0; i < m; i++)
		{
			int a, b;
			double c;
			cin >> a >> b >> c;
			adj[a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
		}
		printf("%.10f\n", dijkstra());
	}
	return 0;
}
