#include <bits/stdc++.h>
using namespace std;

int n, d[12], dp[12][12][2], l, r;

// This function returns the number of possible
// numbers that satisfy the passed arguments
int fun(int pos, int prev, bool lim)
{
	if(pos < 0) return 1; // Base case
	if(dp[pos][prev][lim] != -1) return dp[pos][prev][lim];
	// Do we have a upper bound restriction
	// on our current digit?
	int upper = lim ? d[pos] : 9;
	int ret = 0;
	for(int i = 0; i <= upper; i++)
		if(abs(i - prev) >= 2)
			ret += fun(pos - 1, i, lim && (i == d[pos]));
	return dp[pos][prev][lim] = ret;
}

int solve(int x)
{
	n = 0; // n is the number of digits in the number
	for(; x != 0; x /= 10) d[n++] = x % 10; // Separation of digits & count the number of digits
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		// We only need to worry about the upper limit
		// when the # of digits we have right now == # of digits of x
		// in that case, the upper limit's digit is the most
		// significant digit of our upper limit x.
		int lim = (i == n - 1) ? d[n - 1] : 9;
		for(int j = 1; j <= lim; j++) // j = 1 avoid leading zeros
		// The limit argument of fun is essentially
		// a boolean indicating whether the next digit has
		// a limitation (i.e., is it going to be bounded).
			cnt += fun(i - 1, j, i == n - 1 && j == d[n - 1]);
	}
	
	return cnt;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &l, &r); // Take input :)
	printf("%d", solve(r) - solve(l - 1));
}
