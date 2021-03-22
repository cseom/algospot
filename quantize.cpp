#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 987654321;

int cache[101][11];
int n, s;
int a[101], pSum[101], pSqSum[101];

int minError(int lo, int hi)
{
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);

	int m = int(0.5 + (double)sum / (hi - lo + 1));
	int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);
	return ret;
}

int quantize(int from, int parts)
{
	if (from == n)
		return 0;
	if (parts == 0)
		return INF;
	int& ret = cache[from][parts];
	if (ret != -1)
		return ret;
	ret = INF;
	for (int partSize = 1; from + partSize <= n; partSize++)
		ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));
	return ret;
}

void precalc()
{
	sort(a, a + n);
	pSum[0] = a[0];
	pSqSum[0] = a[0] * a[0];
	for (int i = 1; i < n; i++)
	{
		pSum[i] = pSum[i - 1] + a[i];
		pSqSum[i] = pSqSum[i - 1] + a[i] * a[i];
	}
}

int main(void)
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		memset(cache, -1, sizeof(cache));
		cin >> n >> s;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		precalc();
		cout << quantize(0, s) << "\n";
	}
}
