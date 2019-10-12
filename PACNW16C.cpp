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

int N, K, R, cnt, BIT[100005];
bool arr[100005];

void add(int n, int k)
{
	for(int i = n; i <= N; i += LSB(i))
		BIT[i] += k;
}

int sum(int n)
{
	int sum = 0;
	for(int i = n; i > 0; i -= LSB(i))
		sum += BIT[i];
	return sum;
}

int main()
{
	scanf("%d %d %d", &N, &K, &R);
	for(int i = 0, a; i < K; i++)
	{
		scanf("%d", &a);
		arr[a] = true;
		add(a, 1);
	}
	R--;
	for(int i = 1; i <= N-R; i++)
	{
		int has = sum(i+R) - sum(i-1), a = i+R;
		//printf("%d ", has);
		if(has >= 2) continue;
		for(int j = 0; j < 2 - has; j++)
		{
			while(arr[a--] && a >= i);
			arr[a+1] = true;
			add(a+1,1);
			//printf("insert at %d\n",a+1);
			cnt++;
		}
	}
	printf("%d", cnt);
}
