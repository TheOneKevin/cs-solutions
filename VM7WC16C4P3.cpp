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

int D, I, R, dp[1003][1003];
string s1, s2;

int f(int i, int j)
{
	if(i == 0 && j == 0) return 0;
	if(dp[i][j] != 0) return dp[i][j];
	if(i == 0) return dp[i][j]=j*I;
	if(j == 0) return dp[i][j]=i*D;
	if(s1.c_str()[i-1] == s2.c_str()[j-1])
		return dp[i][j]=f(i-1, j-1);
	return dp[i][j]=min({f(i-1,j)+D, f(i,j-1)+I, f(i-1,j-1)+R});
}

int main()
{
	// I hate c++
	cin >> D; cin >> I; cin >> R;
	cin >> s1; cin >> s2;
	printf("%d", f(s1.length(), s2.length()));
}
