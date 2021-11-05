#include <iostream>
#include <iomanip>
using namespace std;

long long L = 2000000000;

int ratio(long long b, long long a)
{
	return (a * 100) / b;
}

int neededGames(long long games, long long won)
{
	if (ratio(games, won) == ratio(games + L, won + L))
		return -1;
	long long lo = 0;
	long long hi = L;
	while (lo + 1 < hi)
	{
		long long mid = (lo + hi) / 2;
		if (ratio(games, won) == ratio(games + mid, won + mid))
			lo = mid;
		else
			hi = mid;
	}
	return hi;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;

	cin >> tc;
	while (tc--)
	{
		int n, m;
		cin >> n >> m;
		cout << neededGames(n, m) << "\n";
	}

}
