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

struct node
{
	int a, b;
	bool s;
};

int N, M, rec;
node s[1000006];
string lst = "";
bool lst[1000006];

bool traverse(int n)
{
	int i = 1;
	while(true)
	{
		s[i].s = !s[i].s;
		lst[i] = s[i].s;
		i = !s[i].s ? s[i].b : s[i].a;
		if(i == N + 1) break;
	}
	if(st == lst0)
		return true;
	rec++;
	//cout << st << endl;
	lst = st;
	return false;
}

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 1, a, b; i <= N; i++)
	{
		scanf("%d %d", &a, &b);
		s[i] = { a, b, false };
		lst += "0";
		lst0 += "0";
	}
	rec++;
	for(int i = 1; !traverse(i); i++) if(i >= M) { printf("%s\n", lst.c_str()); return 0; }
	//printf("Repeating period = %d\n", rec);
	lst = lst0;
	for(int i = 1; i <= M % rec; i++) traverse(i);
	printf("%s\n", lst.c_str());
	
	//for(int i = 1; i <= N; i++)
	//	printf("%d", s[i].s);
	//printf("\n");
}
