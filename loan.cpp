#include <iostream>
#include <iomanip>
using namespace std;

double balance(double amount, int duration, double rates, double monthlyPayment)
{
	double balance = amount;
	for (int i = 0; i < duration; i++)
	{
		balance *= (1.0 + (rates / 12.0) / 100.0);
		balance -= monthlyPayment;
	}
	return balance;
}

double payment(double amount, int duration, double rates)
{
	double lo = 0;
	double hi = amount * (1.0 + (rates / 12.0) / 100.0);
	for (int iter = 0; iter < 100; iter++)
	{
		double mid = (lo + hi) / 2.0;
		if (balance(amount, duration, rates, mid) <= 0)
			hi = mid;
		else
			lo = mid;
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
		double amount, rates;
		int duration;

		cin >> amount >> duration >> rates;
		cout << fixed << setprecision(10);
		cout << payment(amount, duration, rates) << "\n";
	}

}
