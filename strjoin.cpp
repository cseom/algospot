#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int contact(vector<int>& lengths)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < lengths.size(); i++)
		pq.push(lengths[i]);
	int ret = 0;
	while (pq.size() > 1)
	{
		int min1 = pq.top();
		pq.pop();
		int min2 = pq.top();
		pq.pop();
		pq.push(min1 + min2);
		ret += min1 + min2;
	}
	return ret;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> lengths(n);
		for (int i = 0; i < n; i++)
			cin >> lengths[i];
		cout << contact(lengths) << '\n';
	}

	return 0;
}
