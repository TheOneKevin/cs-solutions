/*
 * main.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: Kevin
 */

#include <bits/stdc++.h>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef bitset<10> bs;
bs grid[10];

int N, G;
unordered_map<int, int> mp;

int main()
{
	scanf("%d\n", &N);
	scanf("%d\n", &G);
	for(int i = 0; i < G; i++)
	{
		for(int x = 0; x < N; x++)
		{
			string s; getline(std::cin, s);
			for(int y = 0; y < N; y++)
				grid[x][y] = s[y] == 'R' ? 0 : 1;
		}

		for(int x = 0; x < N - 1; x++)
		{
			for(int y = 0; y < N - 1; y++)
				if(grid[x][y] == 1)
				{
					grid[x][y].flip();
					grid[x][y + 1].flip();
					grid[x + 1][y].flip();
					grid[x + 1][y + 1].flip();
				}
		}
        int a = 0;
		for(int x = 0; x < N; x++)
			a |= grid[N - 1][x] << x;
		for(int x = 0; x < N - 1; x++)
			a |= grid[x][N - 1] << (N + x);

		if(mp.find(a)==mp.end())mp[a]=1;
		else mp[a]++; // Add to map

		grid[0].reset(); grid[1].reset(); grid[2].reset(); grid[3].reset(); grid[4].reset();
		grid[5].reset(); grid[6].reset(); grid[7].reset(); grid[8].reset(); grid[9].reset();
	}

	int ans = 0;
	for (auto it = mp.begin(); it != mp.end(); it++)
	{
		int count = it -> second;
		ans += (count * (count - 1)) / 2;
	}

	printf("%d", ans);
}