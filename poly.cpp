#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 10000000;

int cache[101][101];

int poly(int n, int first)
{
    if (n == first)
        return 1;
    int& ret = cache[n][first];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int second = 1; second <= n - first; second++)
    {
        int add = second + first - 1;
        add *= poly(n - first, second);
        add %= MOD;
        ret += add;
        ret %= MOD;
    }
    return ret;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        memset(cache, -1, sizeof(cache));
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += poly(n, i);
            ans %= MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}
