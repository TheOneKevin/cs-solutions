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

#define PRM(x) fct[x]=x

int fct[33];

int main()
{
    // Hehe
    PRM(2),PRM(3),PRM(5),PRM(7),PRM(11),PRM(13),PRM(17),PRM(19),PRM(23),PRM(29),PRM(31);
for(int _ = 0; _ < 5; _++) {
    int N = 0, n, cnt = 0;
    scanf("%d", &N);
    n = N;
    for(int i = 2; i < n; i++)
        if(fct[i] == i)
            while(N % i == 0)
                N /= i, cnt++;
    printf("%d\n", cnt);
}}
