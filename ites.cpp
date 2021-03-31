#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct RNG
{
	unsigned seed;
	RNG() : seed(1983) {}
	unsigned next()
	{
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}
};

int countRanges(int n, int k)
{
	RNG rng;
	queue<int> range;
	int ret = 0;
	int rangeSum = 0;
	for (int i = 0; i < n; i++)
	{
		int newSignal = rng.next();
		rangeSum += newSignal;
		range.push(newSignal);
		
		while (rangeSum > k)
		{
			rangeSum -= range.front();
			range.pop();
		}
		if (rangeSum == k)
			ret++;
	}
	return ret;
}

int main(void)
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		int k, n;
		scanf("%d %d", &k, &n);
		printf("%d\n", countRanges(n, k));
	}
	return 0;
}
