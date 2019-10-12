#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define MOD 1000000007 // Change me!
#define lsb(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define ilog2(n) sizeof(int)*8-__builtin_clz(n)-1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
#define ff first
#define ss second
#define sc(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define smod(a,b) (((a)%MOD-(b)%MOD+MOD)%MOD)
#define amod(a,b) (((a)%MOD+(b)%MOD)%MOD)
#define cintie { cin.sync_with_stdio(0); cin.tie(0); }
typedef long long ll;
typedef struct{int x,y;}vec;
typedef pair<int, int> ip;

int N, M, dp[1003][1003];
string s1, s2;

bool h1(int a, int b, int c)
{
	return s1.substr(a-c,c) == s1.substr(b-c,c);
}

int f(int i, int j)
{
	if(i < 0 || j < 0) return INF;
	if(i==0&&j==0) return 0;
	if(i==0) return j/3+(j%3)/2+(j%3)%2; // Insert All
	if(j==0) return i/3+(i%3)/2+(i%3)%2; // Delete All
	if(dp[i][j]!=0)return dp[i][j];
	if(s1.c_str()[i-1] == s2.c_str()[j-1])
		return dp[i][j]=f(i-1, j-1);
	return dp[i][j]=min({
		f(i-1,j)+1, f(i,j-1)+1, f(i-1,j-1)+1,
		f(i-2,j)+1, f(i,j-2)+1,
		f(i-3,j)+1, f(i,j-3)+1
	});
}

int main()
{
	cintie;
	cin >> N >> M;
	cin	>> s1 >> s2;
	cout << f(s1.length(), s2.length());
}