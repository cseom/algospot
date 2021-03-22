#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int S[501];
int cache[501];

int lis(int start)
{
	int& ret = cache[start + 1];
	if (ret != -1)
		return ret;
	ret = 1;
	for (int next = start + 1; next < n; next++)
	{
		if (start == -1 || S[start] < S[next])
			ret = max(ret, lis(next) + 1);
	}
	return ret;
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n;
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; i++)
			cin >> S[i];
		cout << lis(-1) - 1 << "\n";
	}
	return 0;
}
