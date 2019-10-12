#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define lsb (n) ((n)&-(n))
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(int)*8-__builtin_clz(n)-1
#define mid (n, m) (((m)+(n))/2)
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
typedef struct{int x,y,c;}vec;
typedef pair<int, int> ip;

int T;
char adj[22][22];
bool vis[22][22];

int main()
{
	scanf("%d", &T);
	for(int _ = 0, r, c; _ < T; _++)
	{
		int cnt = -1;
		memset(vis, 0, sizeof(vis));
		memset(adj, 0, sizeof(adj));
		
		scanf("%d %d", &r, &c);
		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= c; j++)
				scanf(" %c", &adj[j][i]);
		
		if(adj[c][r]=='*')
		{
			printf("-1\n");
			continue;
		}
			
		queue<vec> q;
		q.push({1,1,1});
		while(!q.empty())
		{
			vec u = q.front(); q.pop();
			if(u.x == c && u.y == r)
			{
				cnt = u.c;
				break;
			}
			if(vis[u.x][u.y]) continue;
			//cout << adj[u.x][u.y] << endl;
			vis[u.x][u.y] = true;
			switch(adj[u.x][u.y])
			{
				case '-':
					q.push({u.x-1,u.y,u.c+1});
					q.push({u.x+1,u.y,u.c+1});
					break;
				case '+':
					q.push({u.x-1,u.y,u.c+1});
					q.push({u.x+1,u.y,u.c+1});
					q.push({u.x,u.y+1,u.c+1});
					q.push({u.x,u.y-1,u.c+1});
					break;
				case '|':
					q.push({u.x,u.y+1,u.c+1});
					q.push({u.x,u.y-1,u.c+1});
					break;
			}
		}
		printf("%d\n", cnt);
	}
}