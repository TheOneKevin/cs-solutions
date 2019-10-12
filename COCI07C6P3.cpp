#include <bits/stdc++.h>
using namespace std;

/**
 * If A % N = B % N
 * If B - A = D -> B = D + A
 * So A % N = (D + A) % N
 *    A % N = D % N + A % N
 *    D % N = 0
 * QED
 */

int N, arr[101];

inline void check(int vi)
{
	// Check every array value with v value to see
	// if the modulus remains constant
	int tmp = arr[0] % vi;
	int j = 1;
	for(; j < N; j++)
		if(arr[j] % vi != tmp)
			break;
	if(j == N && vi != 1) printf("%d ", vi);
}

int main()
{
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + 101, greater<int>());
	int D = arr[0] /* Largest */ - arr[N - 1]; // Smallest
	// Factor D now
	// O(sqrt(N)), worst case ~31623 loops, not bad
	for(int i = 1; i * i <= D; i++) {
		if(D % i == 0)
		{
			// realized we can do the check while factoring ^-^
			check(i);
			if(i != D / i)
				check(D / i);
		}
	}
}
