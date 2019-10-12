/*

This works because of parity.
p1 p2 p1
p3 p4 p3
p1 p2 p1
And the symmetry of the irreducible cases.

*/

#include <bits/stdc++.h>
using namespace std;
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }

// Normal stuff
int A[4][4], tA[4][4]; bool B[4][4], tB[4][4];
// Frequency
int fr[4], fc[4], nr[4], nc[4], nx;
int fuckccc;

// Fill all trivial gaps
void fill(int (&a)[4][4], bool (&b)[4][4])
{
	for(int i = 1; i <= 3; i++)
	{
		if(b[i][1]&&!b[i][2]&&b[i][3]) b[i][2]=true, a[i][2]=(a[i][3]+a[i][1])/2, nx--;
		else if(!b[i][1]&&b[i][2]&&b[i][3]) b[i][1]=true, a[i][1]=2*a[i][2]-a[i][3], nx--;
		else if(b[i][1]&&b[i][2]&&!b[i][3]) b[i][3]=true, a[i][3]=2*a[i][2]-a[i][1], nx--;
	}
	
	for(int j = 1; j <= 3; j++)
	{
		if(b[1][j]&&!b[2][j]&&b[3][j]) b[2][j]=true, a[2][j]=(a[3][j]+a[1][j])/2, nx--;
		else if(!b[1][j]&&b[2][j]&&b[3][j]) b[1][j]=true, a[1][j]=2*a[2][j]-a[3][j], nx--;
		else if(b[1][j]&&b[2][j]&&!b[3][j]) b[3][j]=true, a[3][j]=2*a[2][j]-a[1][j], nx--;
	}
}

// Fill row
void fillR(int (&arr)[4][4], bool (&ful)[4][4], int k)
{
	for(int i = 1; i <= 3; i++)
		arr[k][i] = nr[k], ful[k][i] = true;
}

// Fill column
void fillC(int (&arr)[4][4], bool (&ful)[4][4], int k)
{
	for(int i = 1; i <= 3; i++)
		arr[i][k] = nc[k], ful[i][k] = true;
}

// Is current square a VALID configuration
bool isValid(int arr[4][4], bool ful[4][4])
{
	if((ful[1][1]&&ful[1][2]&&ful[1][3])&&((arr[1][1]+arr[1][3])/2.0!=(double)arr[1][2])) return false;
	if((ful[2][1]&&ful[2][2]&&ful[2][3])&&((arr[2][1]+arr[2][3])/2.0!=(double)arr[2][2])) return false;
	if((ful[3][1]&&ful[3][2]&&ful[3][3])&&((arr[3][1]+arr[3][3])/2.0!=(double)arr[3][2])) return false;
	if((ful[1][1]&&ful[2][1]&&ful[3][1])&&((arr[1][1]+arr[3][1])/2.0!=(double)arr[2][1])) return false;
	if((ful[1][2]&&ful[2][2]&&ful[3][2])&&((arr[1][2]+arr[3][2])/2.0!=(double)arr[2][2])) return false;
	if((ful[1][3]&&ful[2][3]&&ful[3][3])&&((arr[1][3]+arr[3][3])/2.0!=(double)arr[2][3])) return false;
	// Check bounds
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
			if(ful[i][j] && (arr[i][j] > 1e9 || arr[i][j] < -1e9))
				return false;
	return true;
}

// Is current square a COMPLETE configuration
bool isComplete(bool ful[4][4])
{
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
			if(!ful[i][j]) return false;
	return true;
}

int main()
{
	// Input
	cintie(0);
	
	for(int i = 1; i <= 3; i++) // Row idx
	{
		for(int j = 1; j <= 3; j++) // Col idx
		{
			string s; cin >> s;
			if(s == "X")
				B[i][j] = false, nx++;
			else
				A[i][j] = stoi(s), B[i][j] = true, fuckccc = stoi(s);
		}
	}
	// Cases of irreducible n = 9 (trivial output)...
	if(nx == 9)
	{
		cout << "1 1 1\n1 1 1\n1 1 1";
		return 0;
	}
	// and n = 8 (simple reduction into homogeneous grid)
	if(nx == 8)
	{
		for(int i = 1; i <= 3; i++)
			for(int j = 1; j <= 3; j++)
				A[i][j] = fuckccc;
		goto end;
	}
	// Attempt reduction
	for(int i = 0; i < 5; i++) fill(A, B);
	if(isValid(A, B) && isComplete(B)) goto end;
	for(int i = 1; i <= 3; i++)
	{
		for(int j = 1; j <= 3; j++)
		{
			if(B[i][j])
			{
				// Get column and row frequency, and an element
				// as we're only interested in lone elements
				nr[i] = A[i][j], fr[i]++;
				nc[j] = A[i][j], fc[j]++;
			}
		}
	}
	// Trivial case of irreducible n = 7
	if(nx == 7)
	{
		copy(&A[0][0], &A[0][0]+16, &tA[0][0]);
		copy(&B[0][0], &B[0][0]+16, &tB[0][0]);
		for(int i = 1; i <= 3; i++)
			if(fr[i] == 1) fillR(tA, tB, i);
		for(int i = 0; i < 5; i++) fill(tA, tB);
		if(isValid(tA, tB) && isComplete(tB)) { copy(&tA[0][0], &tA[0][0]+16, &A[0][0]); goto end; }
		copy(&A[0][0], &A[0][0]+16, &tA[0][0]);
		copy(&B[0][0], &B[0][0]+16, &tB[0][0]);
		for(int i = 1; i <= 3; i++)
			if(fc[i] == 1) fillC(tA, tB, i);
		for(int i = 0; i < 5; i++) fill(tA, tB);
		if(isValid(tA, tB) && isComplete(tB)) { copy(&tA[0][0], &tA[0][0]+16, &A[0][0]); goto end; }
	}
	// Trivial case of irreducible n = 6
	// lines parallel to orthogonal axes (collinear in N/3Z)
	if(nx == 6)
	{
		copy(&A[0][0], &A[0][0]+16, &tA[0][0]);
		copy(&B[0][0], &B[0][0]+16, &tB[0][0]);
		for(int i = 1; i <= 3; i++) if(fr[i] == 1) fillR(tA, tB, i);
		for(int i = 1; i <= 3; i++) if(fc[i] == 1) fillC(tA, tB, i);
		for(int i = 0; i < 5; i++) fill(tA, tB);
		if(isValid(tA, tB) && isComplete(tB)) { copy(&tA[0][0], &tA[0][0]+16, &A[0][0]); goto end; }
	}
	// Let's kill ourselves.
	// Try to expand all possible rows
	for(int i = 1; i <= 3; i++)
	{
		if(fr[i] == 1)
		{
			copy(&A[0][0], &A[0][0]+16, &tA[0][0]);
			copy(&B[0][0], &B[0][0]+16, &tB[0][0]);
			fillR(tA, tB, i);
			// Attempt reduction
			for(int i = 0; i < 5; i++) fill(tA, tB);
			// We found a valid configuration!
			if(isValid(tA, tB) && isComplete(tB)) { copy(&tA[0][0], &tA[0][0]+16, &A[0][0]); goto end; }
		}
	}
	// Try to expand all possible columns
	for(int i = 1; i <= 3; i++)
	{
		if(fc[i] == 1)
		{
			copy(&A[0][0], &A[0][0]+16, &tA[0][0]);
			copy(&B[0][0], &B[0][0]+16, &tB[0][0]);
			fillC(tA, tB, i);
			for(int i = 0; i < 5; i++) fill(tA, tB);
			if(isValid(tA, tB) && isComplete(tB)) { copy(&tA[0][0], &tA[0][0]+16, &A[0][0]); goto end; }
		}
	}
	//cout << "Welp." << endl;
end:
	for(int i = 1; i <= 3; i++)
	{
		for(int j = 1; j <= 3; j++)
			cout << A[i][j] << " ";
		cout << "\n";
	}
}
