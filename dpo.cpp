#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define lsb(n)  ((n)&-(n))
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(n)*8-__builtin_clz(n)-1
#define mid(n,m)(((m)+(n))/2)
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
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

int N, a[22][22], dp[22][pow2(21)+1];

int f(int m, int bt)
{
    if(m >= N) return dp[m][bt]=1;
    if(dp[m][bt] != -1) return dp[m][bt];
    int res = 0;
    for(int i = 0; i < N; i++)
        if(a[m][i]&&!(bt&pow2(i)))
            res = amod(res, f(m+1, bt|pow2(i)));
    return dp[m][bt]=res%MOD;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &a[i][j]);
    printf("%d", f(0,0));
}
