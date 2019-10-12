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

int N, cnt, t1, g[101];
bool vis[101];
vector<int> cyc[101];

void bfs(int v)
{
    int u = v;
    while(true)
    {
        //printf("%d ", u);
        cyc[cnt].push_back(u);
        t1++;
        if(vis[g[u]]) break;
        u = g[u];
        vis[u] = true;
    }
    cnt++;
}

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        // Element i must be in position a when sorted
        scanf("%d", &g[i]);
    }
    
    for(int i = 1; i <= N; i++)
    {
        if(vis[i]) continue;
        vis[i] = true;
        if(g[i] != i)        
            bfs(i);
    }
    if(cnt > 1)
        printf("2\n");
    else if(cnt == 1)
        printf("1\n");
    else if(cnt == 0)
    {
        printf("0\n");
        return 0;
    }
    printf("%d ", t1);
    for(int i = 0; i < cnt; i++)
        for(int u : cyc[i])
            printf("%d ", u);
    printf("\n");
    if(cnt == 1) return 0;
    printf("%d ", cnt);
    for(int i = cnt-1; i >= 0; i--)
        printf("%d ", (cyc[i])[0]);
    printf("\n");
}
