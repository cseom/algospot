#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int cache[101][101];
string w, s;

bool match(int W, int S)
{
	int& ret = cache[W][S];
	while (S < s.size() && W < w.size() && (w[W] == '?' || w[W] == s[S]))
	{
		S++;
		W++;
	}
	if (S < s.size() && W < w.size() && (w[W] == '?' || w[W] == s[S]))
		return ret = match(W + 1, S + 1);
	if (W == w.size())
		return ret = (S == s.size());
	if (w[W] == '*')
	{
		if (match(W + 1, S) || (S < s.size() && match(W, S + 1)))
			return ret = true;
		/*
		for (int skip = 0; S + skip <= s.size(); skip++)
		{
			if (match(W + 1, S + skip))
				return ret = true;
		}
		*/
	}
	return ret = false;
}

int main(void)
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		memset(cache, -1, sizeof(cache));
		cin >> w;
		cin >> n;
		vector<string> ans;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			if (match(0, 0))
				ans.push_back(s);
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << "\n";
	}

	return 0;
}
