#include <bits/stdc++.h>
using namespace std;

int main()
{
	
}

/**

arr[i][j] = 
3 3 4 1 3 4 4
4 2 5 1 5 5 4
5 5 1 3 4 4 4

dp[i][j] =
    [1][2][3][4][5][6][7]
[1]  3  6 10 11 14 18 22
[2]  -  5 10 11 16 19 22
[3]  -  -  6  9 13 17 21

The first question is always assigned to the first guy
Start from the top of the dp table (dp[3][j])
Build the first row as a normal prefix sum array

The second row of dp starts at index i = 2 as i = 1 is always
assigned to the first guy.

dp[i][j] = min(dp[i - 1][j - 1] + arr[i][j], dp[i][j - 1] + arr[i][j])

The result of the dp table is at the bottom right corner

*/
