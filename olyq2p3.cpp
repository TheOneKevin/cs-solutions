#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define lsb(n) ((n)&-(n))
#define pow2(n) (1<<(n))
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
#define btst(a,b) ((a) & (1 << (b)))
// Typedefs
typedef long long ll;
typedef struct{int x,y;}vec;
typedef pair<int, int> ip;

vector<int> v;
int N=4, K=2, dp[11][51][1027];
bool arr[2049];
set<int> all;

void A(int bt, int k)
{
    if(k == 0) return;
    for(int i = 1; i <= N; i++)
        if(!btst(bt, i+1)&&!btst(bt, i-1))
            arr[bt|(1<<i)] = true, A(bt|(1<<i), k-1);
}

bool isValid(int a, int b)
{
	a <<= 1; b <<= 1;
	if(a == b) return false;
    for(int i = 1; i <= N; i++)
    {
        if(btst(a, i) && btst(b, i)) return false;
        if(btst(a, i+1) && btst(b, i)) return false;
        if(btst(a, i-1) && btst(b, i)) return false;
    }
    return true;
}

int f(int i, int k, int b)
{
    if(k == 0 && i == 0) return 1;
    if(k <= 0 || i <= 0) return 0;
    int ans = 0;
    for(int a = 0; a <= 1024; a++)
        if(arr[a<<1] && isValid(a,b))
            ans += f(i-1, k-__builtin_popcount(a), a);
    return ans;
}

int main()
{
    cintie;
	arr[0] = true;
    cin >> N >> K;
    A(0, K);
	
	/*int ans = 0;
    for(int i = 0; i <= 1024; i++)
		if(arr[i<<1])
			ans += f(N, K, i);
	cout << ans << endl;
	return 0;*/
	
	cout << f(N, K, 0) << endl;
	
	cout << isValid(0b0101, 0b1000) << endl;
	cout << isValid(0b1010, 0b0001) << endl;
	for(int i = 0; i <= 1024; i++)
    {
        if(arr[i<<1])
        {
            bitset<10> x(i);
            cout << __builtin_popcount(i) << " " << x << endl;
        }
    }
}
