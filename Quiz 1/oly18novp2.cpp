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

int N;

int main()
{
	scanf("%d", &N);
	for(int i = 0, d, p; i < N; i++)
	{
		scanf("%d %d", &d, &p);
	}
	
	
}

/**

put all available gates into a sorted set
use the lower_bound to find the first gate available
less than or equal to the #, if found, remove it 
from the set. count++ each time (a sorted set is logn)
so, O(nlongn)

disjoint set:
sort all gates, merge with left each time, make parent the
node to the left. If the parent node is 0, we cannot dock, or
we can dock at the gate which is the parent's #.

for roger's homework question,
we sort the points in descending order, then we can apply the
same concept as Gates (CCC S3).

*/
