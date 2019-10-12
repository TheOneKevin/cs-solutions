#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(n)*8-__builtin_clz(n)-1
#define mid(n,m)(((m)+(n))/2)
#define ff first
#define ss second
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }
// Typedefs
typedef long long ll;
typedef struct{int x,y;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

int x, y, mw = INF, mh = INF;
int mat[10][10] = {
	{ 73, 72, 71, 70, 69, 68, 67, 66, 65, 100 },
	{ 74, 43, 42, 41, 40, 39, 38, 37, 64, 99 },
	{ 75, 44, 21, 20, 19, 18, 17, 36, 63, 98 },
	{ 76, 45, 22,  7,  6,  5, 16, 35, 62, 97 },
	{ 77, 46, 23,  8,  1,  4, 15, 34, 61, 96 },
	{ 78, 47, 24,  9,  2,  3, 14, 33, 60, 95 },
	{ 79, 48, 25, 10, 11, 12, 13, 32, 59, 94 },
	{ 80, 49, 26, 27, 28, 29, 30, 31, 58, 93 },
	{ 81, 50, 51, 52, 53, 54, 55, 56, 57, 92 },
	{ 82, 83, 84, 85, 86, 87, 88, 89, 90, 91 }
};

int main()
{
	scanf("%d %d", &x, &y);
	// Correct matrix
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			mat[i][j] += x-1;
	// Set all larger values to zero
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			if(mat[i][j] > y)
				mat[i][j] = 0;
	// Find minimum width and height
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			if(mat[i][j] != 0)
				mw = min(mw, j), mh = min(mh, i);
	for(int i = mh; i < 10; i++)
	{
		for(int j = mw; j < 10; j++)
		{
			if(mat[i][j] != 0) printf("%2d ", mat[i][j]);
			else printf("   ");
		}
		printf("\n");
	}
}

/*
     +
cccc+c
coo+oc
co+xoc
coxxoc
cooooc
cccccc

N
0 -> 4  4*1
1 -> 12 4*3
2 -> 20 4*5

(2+2N)^2-(2+2N-2)^2
=4(N+1)^2-4N^2
=4N^2+8N+4-4N^2
=8N+4
=4(2N+1)

All odd numbers.

*/
