#include <iostream>
#include <limits>
#include <cstring>
#include <algorithm>
using namespace std;

const long long NEGINF = -2147483649;

int n, m;
int A[501], B[501];
int cache[501][501];

int jlis(int indexA, int indexB)
{
	int& ret = cache[indexA + 1][indexB + 1];
	if (ret != -1)
		return ret;
	ret = 2;
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]);
	long long maxElement = max(a, b);

	for (int nextA = indexA + 1; nextA < n; nextA++)
	{
		if (maxElement < A[nextA])
			ret = max(ret, jlis(nextA, indexB) + 1);
	}
	for (int nextB = indexB + 1; nextB < m; nextB++)
	{
		if (maxElement < B[nextB])
			ret = max(ret, jlis(indexA, nextB) + 1);
	}
	return ret;
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n >> m;
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; i++)
			cin >> A[i];
		for (int i = 0; i < m; i++)
			cin >> B[i];
		cout << jlis(-1, -1) - 2 << "\n";
	}
	return 0;
}
