#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

vector<int> order;
vector<bool> seen;

void makeGraph(const vector<string>& words)
{
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	for (int j = 1; j < words.size(); ++j)
	{
		int i = j - 1;
		int len = min(words[i].size(), words[j].size());
		for (int k = 0; k < len; ++k)
		{
			if (words[i][k] != words[j][k])
			{
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adj[a][b] = 1;
				break;
			}
		}
	}
}

void dfs(int here)
{
	seen[here] = 1;
	for (int there = 0; there < adj.size(); ++there)
		if (adj[here][there] && !seen[there])
			dfs(there);
	order.push_back(here);
}

vector<int> topologicalSort()
{
	seen = vector<bool>(26, 0);
	for (int i = 0; i < 26; ++i)
	{
		if (!seen[i])
			dfs(i);
	}
	reverse(order.begin(), order.end());
	for (int i = 0; i < 26; ++i)
	{
		for (int j = i + 1; j < 26; ++j)
		{
			if (adj[order[j]][order[i]])
				return vector<int>();
		}
	}
	return order;
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
		int n;
		cin >> n;
		vector<string> words(n);
		for (int i = 0; i < n; i++)
			cin >> words[i];
		order.clear();
		makeGraph(words);
		order = topologicalSort();
		if (!order.empty())
		{
			for (int i = 0; i < 26; i++)
			{
				char c = order[i] + 'a';
				cout << c;
			}
		}
		else
			cout << "INVALID HYPOTHESIS";
		cout << "\n";
	}
	return 0;
}
