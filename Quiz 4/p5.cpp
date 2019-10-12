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

// Have top down to bottom up
// dp1[u][0] = val[u]
// dp1[u][i] = sum of all dp1[v][i-1] (for each i)
// Then...
// dp2[u][i] += dp2[of parent node][i-1] - dp1[i][i-1]

int main()
{

}
