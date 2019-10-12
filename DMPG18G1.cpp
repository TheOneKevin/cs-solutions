#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> bip;

int N, K;
bip chairs[1000001];
stack<int> s;

int main()
{
	for(int i = 0; i < 1000001; i++)
		chairs[i] = { 0, 0 };
	
	scanf("%d %d", &N, &K);
	for(int i = 0, idx; i < K; i++)
		scanf("%d", &idx), chairs[idx - 1] = { 1, 0 };
	for(int i = 1, idx; i <= K + 1; i++)
		scanf("%d", &idx), chairs[idx - 1].second = i;
	
	int i = 0;
	while(true)
	{
		if(chairs[i].first != 2 && chairs[i].second != 0)
		{
			s.push(chairs[i].second);
			chairs[i].second = 0;
		}
		if(chairs[i].first == 1 && !s.empty())
		{
			chairs[i].first = 2;
			chairs[i].second = s.top();
			//printf("a\n");
			s.pop();
			K--;
		}
		
		if(K == 0)
			break;
		
		i = (i + 1) % N;
	}
	
	printf("%d\n", s.top());
}
