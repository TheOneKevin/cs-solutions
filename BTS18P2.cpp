#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define ilog2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
typedef pair<int, int> ip;
typedef long long ll;

int psa[26][1000001], Q;
char s[1000001], ch;

int main()
{
	scanf("%[^\n]s", s);
	for(int i = 1; i <= (int) strlen(s); i++)
	{
		int k = s[i - 1] - 'a'; 
		for(int j = 0; j < 26; j++)
			psa[j][i] += psa[j][i - 1] + (k == j ? 1 : 0);
	}
	scanf("%d", &Q);
	for(int i = 0, l, r, c; i < Q; i++)
	{
		scanf("%d %d %c", &l, &r, &ch);
		c = (int) ch - 'a';
		printf("%d\n", psa[c][r] - psa[c][l - 1]);
	}
}
