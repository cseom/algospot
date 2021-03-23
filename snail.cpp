#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAX_N = 1001;

int n, m;
double cache[MAX_N][2 * MAX_N + 1];

double climb(int days, int climbed)
{
    if (days == m)
        return climbed >= n ? 1 : 0;
    double& ret = cache[days][climbed];
    if (ret != -1)
        return ret;
    return ret = 0.25 * climb(days + 1, climbed + 1) + 0.75 * climb(days + 1, climbed + 2);
}

int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        for (int i = 0; i < MAX_N; i++)
        {
            for (int j = 0; j < 2 * MAX_N + 1; j++)
                cache[i][j] = -1;
        }
        scanf("%d %d", &n, &m);
        printf("%.10lf\n", climb(0, 0));
    }
    return 0;
}
