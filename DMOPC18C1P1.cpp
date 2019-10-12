#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ip;
int N, A[200003];
vector<ip> v;

int main()
{
	scanf("%d", &N);
	if(N <= 2) { printf("YES"); return 0; }
	
	bool fl0 = false, fl1 = false, fl2 = false, fl3 = false, isSorted = true, canSort = true;
	
	for(int i = 0, a = -1, l, r; i < N; i++)
	{
		scanf("%d", &A[i]);
		if(A[i] == 0)
		{
			if(fl2) r = i; else l = i, r = i;
			if(!fl2) fl2 = true;
			if(i == N - 1) v.push_back({l, r});
			continue;
		}
		// Track all zeroes
		if(fl2) v.push_back({l, r}), fl2 = false;
		// Determine whether the array is sorted
		if(a != -1 && !fl1 && A[i] != a) fl0 = A[i] > a, fl1 = true;
		if(fl1 && fl0) isSorted &= A[i] >= a;
		else if(fl1 && !fl0) isSorted &= A[i] <= a;
		a = A[i];
	}
	
	if(!isSorted) { printf("NO"); return 0; }
	
	int lr = 0x3F3F3F3F, a = 0;
	for(ip e : v)
	{
		int l = e.first, r = e.second;
		//cout << l << " " << r << endl;
		if(l == 0) canSort &= true;
		else
		{
			for(int i = lr; i <= l - 1; i++)
			{
				//cout << A[i] << " " << i << endl;
				if(!fl3) a = A[i], fl3 = true;
				canSort &= A[i] == a;
			}
		}
		
		lr = r + 1;
	}
	
	printf(canSort ? "YES" : "NO");
}
