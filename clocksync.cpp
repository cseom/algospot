#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define SWITCHES 10
#define CLOCKS 16
#define INF 9999

const char linked[SWITCHES][CLOCKS + 1]
{
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};

bool areAligned(vector<int>& clocks)
{
	for (int i = 0; i < CLOCKS; i++)
	{
		if (clocks[i] != 12)
			return false;
	}
	return true;
}

void push(vector<int>& clocks, int swtch)
{
	for (int clock = 0; clock < CLOCKS; clock++)
	{
		if (linked[swtch][clock] == 'x')
		{
			clocks[clock] += 3;
			if (clocks[clock] == 15)
				clocks[clock] = 3;
		}
	}
}

int solve(vector<int>& clocks, int swtch)
{
	if (swtch == SWITCHES)
		return areAligned(clocks) ? 0 : INF;
	int ret = INF;
	for (int cnt = 0; cnt < 4; cnt++)
	{
		ret = min(ret, cnt + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}
	return ret;
}

int main(void)
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		int ans;
		vector<int> clocks(CLOCKS);
		for (int i = 0; i < CLOCKS; i++)
			scanf("%d", &clocks[i]);
		if ((ans = solve(clocks, 0)) == INF)
			ans = -1;
		printf("%d\n", ans);
	}
}
