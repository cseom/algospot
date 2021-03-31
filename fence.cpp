#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
int bruteforce(const vector<int> &h)
{
	int ret = 0;
	for (int left = 0; left < n; left++)
	{
		int minHeight = h[left];
		for (int right = left; right < n; right++)
		{
			minHeight = min(minHeight, h[right]);
			ret = max((right - left + 1) * minHeight, ret);
		}
	}
	return ret;
}
*/

/*
int solveStack(vector<int> &h)
{
	stack<int> remaining;
	int ret = 0;
	h.push_back(0);
	for (int i = 0; i < h.size(); i++)
	{
		while (!remaining.empty() && h[remaining.top()] >= h[i])
		{
			int j = remaining.top();
			remaining.pop();
			int width = -1;

			if (remaining.empty())
				width = i;
			else
				width = i - remaining.top() - 1;
			ret = max(ret, h[j] * width);
		}
		remaining.push(i);
	}
	return ret;
}
*/

int solve(int left, int right, const vector<int> &h)
{
	if (left == right)
		return h[left];
	int	mid = (left + right) / 2;
	int ret = max(solve(left, mid, h), solve(mid + 1, right, h));
	int lo = mid;
	int hi = mid + 1;
	int height = min(h[lo], h[hi]); 
	ret = max(ret, height * 2);

	while (left < lo || hi < right)
	{
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1]))
		{
			++hi;
			height = min(height, h[hi]);
		}
		else
		{
			--lo;
			height = min(height, h[lo]);
		}
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}

int main(void)
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<int> h(n, 0);
		for (int i = 0; i < n; i++)
			cin >> h[i];
		cout << solve(0, h.size() - 1, h) << "\n";
	}

	return (0);
}
