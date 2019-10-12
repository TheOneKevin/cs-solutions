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

int T, N, B;
vector<ip> vv[6];
int dp[6][3003];

int f(int j, int t)
{
	if(j <= 0 && t-1 <= T) return -1;
	if(j <= 0 || t > T) return 0;
	if(dp[t][j] != 0) return dp[t][j];
	
	int ans = -1;
	for(ip e : vv[t])
	{
		int tmp = f(j-e.first,t+1);
		if(tmp >= 0)
			ans = max(ans, tmp + e.second);
	}
	return dp[t][j] = ans;
}

int main()
{
	scanf("%d %d", &T, &N);
	for(int i = 0, c, v, t; i < N; i++)
	{
		scanf("%d %d %d", &c, &v, &t);
		vv[t].push_back({c,v});
	}
	scanf("%d", &B);
	
	for(int i = 1; i <= T; i++)
	{
		if(vv[i].size() == 0)
		{
			printf("-1");
			return 0;
		}
	}
	
	printf("%d", f(B,1));
}