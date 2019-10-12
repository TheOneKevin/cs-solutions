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

int a[10], s;

int main()
{
	for(int i = 0; i < 9; i++) scanf("%d", &a[i]);
	for(int i = 0; i < 9; i++) s += a[i];
	for(int i = 0; i < 9; i++)
	{
		for(int j = i+1; j < 9; j++)
		{
			if(s-a[i]-a[j] == 100)
			{
				for(int k = 0; k < 9; k++)
					if(k != i && k != j)
						printf("%d\n", a[k]);
				return 0;
			}
		}
	}
}
