#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAX_V = 1001;

int V;
vector<int> adj[MAX_V];
vector<bool> visited;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;

int installed;

int dfs(int here)
{
	visited[here] = true;
	int children[3] = { 0,0,0 };
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (!visited[there])
			++children[dfs(there)];
	}
	if (children[UNWATCHED])
	{
		++installed;
		return INSTALLED;
	}
	if (children[INSTALLED])
		return WATCHED;
	return UNWATCHED;
}

int installCamera()
{
	installed = 0;
	visited = vector<bool>(V, false);
	for (int u = 0; u < V; u++)
	{
		if (!visited[u] && dfs(u) == UNWATCHED)
			++installed;
	}
	return installed;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		int h;
		cin >> V >> h;
		for (int i = 0; i < MAX_V; i++)
			adj[i].clear();
		for (int i = 0; i < h; i++)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		cout << installCamera() << "\n";
	}
	return 0;
}
