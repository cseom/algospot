#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 10000;

int n, e[MAX_N], m[MAX_N];

int heat()
{
	vector<pair<int, int>> order;
	for (int i = 0; i < n; i++)
		order.push_back(make_pair(-e[i], i));
	sort(order.begin(), order.end());
	int ret = 0;
	int beginEat = 0;
	for (int i = 0; i < n; i++)
	{
		int box = order[i].second;
		beginEat += m[box];
		ret = max(ret, beginEat + e[box]);
	}
	return ret;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> m[i];
		for (int i = 0; i < n; i++)
			cin >> e[i];
		cout << heat() << '\n';
	}

	return 0;
}
