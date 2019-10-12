#include <bits/stdc++.h>
using namespace std;

vector<int> mod[3];
int N;

int main()
{
	scanf("%d", &N);
	for(int i = 0, a = 0; i < N; i++)
		scanf("%d", &a), mod[a % 3].push_back(a);
	
	int s0 = mod[0].size(), s1 = mod[1].size(), s2 = mod[2].size();
	
	if((s0 > s1 + s2 + 1) || (s0 == 0 && s1 != 0 && s2 != 0))
	{
		printf("impossible");
		return 0;
	}
	
	//cout << s0 << " " << s1 << " " << s2 << endl;
	
	// (a ... a) (3 a 3 ... b 3) (b ... b)
	int l1 = 0, l2 = 0;
	
	for(int i = 0; i < min(s1, s1 - s0 + 1); i++)
	{
		printf("%d ", mod[1].back());
		mod[1].pop_back();
		l1++;
	}
	
	for(int i = 0; i < s0; i++)
	{
		printf("%d ", mod[0].back());
		mod[0].pop_back();
		
		if(!mod[1].empty())
		{
			printf("%d ", mod[1].back());
			mod[1].pop_back();
			l1++;
		}
		else if(!mod[2].empty())
		{
			printf("%d ", mod[2].back());
			mod[2].pop_back();
			l2++;
		}
	}
	
	for(int i = 0; i < s2 - l2; i++)
	{
		printf("%d ", mod[2].back());
		mod[2].pop_back();
	}
}
