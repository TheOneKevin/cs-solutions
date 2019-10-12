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

int N, ans;;
char c[200005];

int main()
{
	scanf("%d ", &N);
	for(int i = 0; i < N; i++) scanf("%c", &c[i]);
	string s(c);
	int mx = 0;
	for(int i = 1; i < N; i++)
		if(s.substr(0, i) == s.substr(N-i, i))
			mx = i;
	//cout << mx << endl;
	// All possible substrings
	for(int i = 0; i < N; i++)
		for(int j = i; j < mx+i; j++)
			if(s.substr(0, j-i+1) == s.substr(i, j-i+1) &&
			   s.substr(N-(j-i+1), j-i+1) == s.substr(i, j-i+1))
			{
				//cout << s.substr(i, j-i+1) << endl;
				ans++;
			}
	printf("%d", ans+1);
}
