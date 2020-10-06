#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<cstdint>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

int main() {

	int n; // nb of machines
	int k; // nb of batteries per chip

	while (scanf("%d %d", &n, &k) ==2) {

		if (n == 0 && k == 0) return 0;

		int nbBatteries = 2*n*k;
		vector<int> batteries(nbBatteries); // stockpile of batteries

	
		for (int i = 0; i<nbBatteries; i++) {
			scanf("%d", &batteries[i]);
		}

		sort(batteries.begin(), batteries.end());

		int left = 0;
		int right = 10e9;
		int d = right;
		
		int min_d = batteries[1]-batteries[0];
		
		while (left < right && right >= min_d) {
			
			int mid = (left+right)/2;
			int remains = n;
			int can_store = 0;
			//vector<int> points;

			for (int i = 0; i<nbBatteries-1; i++) {
				if (batteries[i+1] - batteries[i] <= d) {
					//points.push_back(i);
					i++;
					remains--;
					can_store += 2*(k-1);
				}
				else {
					can_store--;
				}
				if (remains == 0) break;
				if (can_store <= 0) break;
			}

			if (remains > 0)
				left = mid+1;
			else
				right = mid;
			d = max(right, min_d);
		}
		printf("%d\n", d);	
	}
	return 0;
}