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

string a, b;
int dp[3004][30004];

void recprint(int i, int j)
{
	if(i == 0 || j == 0) return;
	if(a.c_str()[i-1] == b.c_str()[j-1])
		recprint(i-1, j-1), printf("%c", a[i-1]);
	else if(dp[i][j-1] > dp[i-1][j])
		recprint(i, j-1);
	else
		recprint(i-1, j);
}

int main()
{
	cin >> a;
	cin >> b;
	for(int i = 1; i <= a.length(); i++)
	{
		for(int j = 1; j <= b.length(); j++)
		{
			if(a.c_str()[i-1] == b.c_str()[j-1])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	
	recprint(a.length(), b.length());
}
