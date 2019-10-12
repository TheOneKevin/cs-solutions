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

// CCC '01 S1 - Keeping Score
// Time (from reading problem to AC submission) [16:50]
int i, cnt, ans, D, E;

int pts(char c)
{
	switch(c)
	{
		case 'A': return 4;
		case 'K': return 3;
		case 'Q': return 2;
		case 'J': return 1;
	}
	return 0;
}

int adj(int sc)
{
	switch(cnt)
	{
		case 0: return sc + 3;
		case 1: return sc + 2;
		case 2: return sc + 1;
		default: return sc;
	}
}

int main()
{
	printf("Cards Dealt Points\n");
	char c; scanf("%c", &c);
	printf("Clubs ");
	while(true)
	{
		scanf("%c", &c);
		if(c == 'D') break;
		D += pts(c);
		printf("%c ", c);
		i++, cnt++;
	}
	ans += adj(D);
	printf("%d\n", adj(D));
	D = 0, cnt = 0;
	
	printf("Diamonds ");
	while(true)
	{
		scanf("%c", &c);
		if(c == 'H') break;
		D += pts(c);
		printf("%c ", c);
		i++, cnt++;
	}
	ans += adj(D);
	printf("%d\n", adj(D));
	D = 0, cnt = 0;
	
	printf("Hearts ");
	while(true)
	{
		scanf("%c", &c);
		if(c == 'S') break;
		D += pts(c);
		printf("%c ", c);
		i++, cnt++;
	}
	ans += adj(D);
	printf("%d\n", adj(D));
	D = 0, cnt = 0;
	
	printf("Spades ");
	while(true)
	{
		scanf("%c", &c);
		if(i == 13) break;
		D += pts(c);
		printf("%c ", c);
		i++, cnt++;
	}
	ans += adj(D);
	printf("%d\n", adj(D));
	
	printf("Total %d\n", ans);
}
