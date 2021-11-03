#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;


// 미분후 미분계수 반환
vector<double> differentiate(const vector<double>& poly)
{
	vector<double> ret;

	int n = poly.size() - 1;
	for (int i = 0; i < poly.size() - 1; i++)
	{
		ret.push_back(poly[i] * n);
		n -= 1;
	}
	return ret;
}

//미분방정식 풀이
vector<double> solveNaive(const vector<double>& poly)
{
	vector<double> ret;
	if (poly.size() == 3)
	{
		double a = poly[0];
		double b = poly[1];
		double c = poly[2];
		double num1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		double num2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		ret.push_back(num1);
		ret.push_back(num2);
	}
	else
		ret.push_back(-poly[1] / poly[0]);
	sort(ret.begin(), ret.end());
	return ret;
}

// poly(x0)값을구함
double evaluate(const vector<double>& poly, double x0)
{
	double ret = 0.0;
	int n = poly.size() - 1;
	for (int i = 0; i < poly.size(); i++)
	{
		ret += (poly[i] * pow(x0, n));
		n -= 1;
	}
	return ret;
}

const double L = 25;

vector<double> solve(const vector<double>& poly)
{
	int n = poly.size() - 1;

	if (n <= 2)
		return solveNaive(poly);

	vector<double> derivative = differentiate(poly);
	vector<double> sols = solve(derivative);

	sols.insert(sols.begin(), -L - 1);
	sols.insert(sols.end(), L + 1);

	vector<double> ret;

	for (int i = 0; i < sols.size() - 1; i++)
	{
		double x1 = sols[i], x2 = sols[i + 1];
		double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);

		if (y1 * y2 > 0)
			continue;

		if (y1 > y2)
		{
			swap(y1, y2);
			swap(x1, x2);
		}
		for (int iter = 0; iter < 100; iter++)
		{
			double mx = (x1 + x2) / 2;
			double my = evaluate(poly, mx);

			if (y1 * my > 0)
			{
				y1 = my;
				x1 = mx;
			}
			else
			{
				x2 = mx;
				y2 = my;
			}
		}
		ret.push_back((x1 + x2) / 2);
	}
	sort(ret.begin(), ret.end());
	return ret;
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
		int n;
		cin >> n;
		vector<double> poly(n + 1);
		for (int i = 0; i < n + 1; i++)
			cin >> poly[i];
		vector<double> ans = solve(poly);
		cout<< fixed << setprecision(12);
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << "\n";
	}

}
