#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define ilog2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
#define loop(x, a, b) for(int x = a; x < b; x++)
#define sc(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
typedef long long ll;
typedef struct{int x,y;}vec;
typedef pair<int, int> ip;

int N, dp[402][402], A[402], p[402];

bool f(int i, int j)
{
	if(dp[i][j] != -1) return dp[i][j];
	// If i >= j return true
	for(int x = i; x < j; x++)
		if(f(i, x) && f(x+1, j))
			if(p[x+1]-p[i] == p[j+1]-p[x+1])
				return dp[i][j] = true;
	
	//BRUTE FORCE!
	for(int k = i; k < j; k++)
		for(int a = k; a < j; a++)
			for(int b = a; b < j; b++)
				if(p[a+1]-p[i] == p[j+1]-p[b+1])
					if(f(i, a) && f(a+1, b) && f(b+1, j))
						return dp[i][j]=true;
	return dp[i][j] = false;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &p[i]);
		dp[i-1][i-1] = true;
		p[i] += p[i-1];
	}
	
	//if(func(0, N - 1)) cout << "true"; else cout << "false";
	f(0, N-1);
	int ret = 0;
	for(int i = 0; i < N; i++)
		for(int j = i; j < N; j++)
			if(dp[i][j])
				ret = max(ret, p[j+1]-p[i]);
	printf("%d", ret);
}