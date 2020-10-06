#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<cstdint>
#include<math.h>

using namespace std;
 


typedef long long int64;


const int INF = 0x3f3f3f3f;
 

const int MAXN = 100000;


int C, n;

int sumDis[MAXN], sumWeight[MAXN];

int f[MAXN];
 


struct Node {

	int x, y, w;

} A[MAXN];
 


int getDis(int i, int j) {

	return abs(A[i].x-A[j].x) + abs(A[i].y-A[j].y);

}
 


int main() {


	int nCase;

	scanf("%d", &nCase);

	while(nCase--) {

		scanf("%d%d", &C, &n);

		for(int i = 1; i <= n; ++i) {
			scanf("%d%d%d", &A[i].x, &A[i].y, &A[i].w);
			sumDis[i] = sumDis[i-1] + getDis(i, i-1);

			sumWeight[i] = sumWeight[i-1] + A[i].w;

		}

		for(int i = 1; i <= n; ++i) {
			f[i] = INF;
			for(int j = i; j >= 1; --j) {
				int w = sumWeight[i] - sumWeight[j-1];
				if(w > C) {break;}
				int dis = getDis(0, j) + sumDis[i] - sumDis[j] + getDis(0, i);
				f[i] = min(f[i], f[j-1] + dis);
			}
		}

		printf("%d\n", f[n]);
		if(nCase) putchar('\n');
	}

	return 0;

}