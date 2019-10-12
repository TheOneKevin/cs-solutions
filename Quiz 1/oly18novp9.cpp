#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define _log2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
typedef pair<int, int> ip;

int main()
{
	
}

/**

Digit wise DP we loop through all possible
digits that satisfy some condition. Usually, we
start with the most significant digit and work our
way downwards.

fun(pos, state, lim);

limit is a boolean that signifies at
index pos, can we place a digit there,
or can we only place the maximum possible
digit there.

Lower 0 2 5
    x ? ? ?
Upper 3 4 7
	  ^ At position 1, we can place any number from 0-3 all inclusive
	    ^ At position 2, we depend on the digit placed before, and place a digit accordingly
If x = 3 4 ? then
           ^ At position 3, lim should be false, so we must place a 7, and thus we're done.

For Roger's number, we have a universal solve(N) function that counts
the number of Roger numbers that fall between 0 and N all inclusive.
Also, the function signiture for fun would be:
fun(int pos, int prev, bool lim);
Where pos is the current position we're at
	 prev is the previous digit we placed
	  lim is the limit, true when we've reached the limit.
Write it recursively.

fun(idx, prev, lim):
	


*/
