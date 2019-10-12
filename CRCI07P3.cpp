#include <bits/stdc++.h>
using namespace std;
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
typedef pair<int, int> ip;

bool check(int mid)
{
	
}

int main()
{

}

/**

int getPrice (int mid):
	X,  10≤X≤100   the amount of the ingredient needed in one serving;
	Y,  1≤Y≤100    the amount of the ingredient already available in the kitchen;
	SM, 1≤SM<100   the size of the smaller package at the store;
	PM, 10≤PM<100  the price of the smaller package;
	SV, SM<SV≤100  the size of the larger package; and
	PV, PM<PV≤100  the price of the larger package.
	
	let mid = proposed number of servings
	let M = mass of ingredients needed
	so, M = X * mid - Y
	
	let P = price = 10001 <- 100 * 100
	
	for i in SM:
		let num_sv = (int) Math.ceil((M - i * SM) / (double) PV)
		P = min(SM * PM + num_sv * PV, P)
	
	return P

bool check(int mid):
	let sum = 0
	for each N
		sum += getPrice(mid)
	return sum <= M
	
	if the sum of the prices is less than or equal to M, then we can provide
	the proposed number of servings (mid)
	
	then do a binary search through all possible values for mid.

*/
