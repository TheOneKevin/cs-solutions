#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define lsb(n)  ((n)&-(n))
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(int)*8-__builtin_clz(n)-1
#define mid(n,m)(((m)+(n))/2)
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
#define sc(x) {do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
#define ff first
#define ss second
#define smod(a,b) (((a)%MOD-(b)%MOD+MOD)%MOD)
#define amod(a,b) (((a)%MOD+(b)%MOD)%MOD)
#define btst(a,b) ((a) & (1 << (b)))
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }
// Typedefs
typedef long long ll;
typedef struct{int x,y;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

int N, Q, R[100005], C[100005];
map<ip, int> mp;

int main()
{
	scanf("%d %d", &N, &Q);
	for(int i = 0; i < Q; i++)
	{
		int c, x, y;
		scanf("%d %d %d", &c, &x, &y);
		if(c == 1)
		{
			if(mp.find({x,y})==mp.end())
				mp[{x,y}]=1;
			else
				mp[{x,y}]++;
			R[y]++;
			C[x]++;
		}
		else if(c == 2)
		{
			//cout << (mp.find({x,y})==mp.end());
			if(mp.find({x,y})==mp.end())
				printf("%d\n", (R[y]+C[x])%2);
			else
				printf("%d\n", (R[y]+C[x]+mp[{x,y}])%2);
		}
	}
}
