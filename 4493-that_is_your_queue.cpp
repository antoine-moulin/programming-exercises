#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<cstdint>
#include<deque>
#include<vector>

using namespace std;

int main() {
	int P, C;
	char D[2];    
	int c = 0;	

	while(true) {
		scanf("%d %d", &P, &C);
		if (P == 0 && C == 0) {return 0;}
	
		deque<int> priorities;
		int min_C_P = (C > P) ? P : C;
		for (int i = 0; i < min_C_P; i++) {priorities.push_back(i+1);}

		vector<int> order;		
	
		int l = 0, x = 0;

		c++;

		for (int i = 0; i < C; i++) {
			scanf("%s", D);

			if (D[0] == 'N') {
				order.push_back(priorities.front());
				priorities.pop_front();
				priorities.push_back(order.back());
			}
			else if (D[0] == 'E') {
				scanf("%d", &x);

				for (int j = 0; j < priorities.size(); j++) {
					if (priorities[j] == x) {
						priorities.erase(priorities.begin()+j);
					}
				}
						
				priorities.push_front(x);

				x = 0;
				l++;
			}
		}

		printf("Case %d:\n", c);
		for (int i = 0; i < C-l; i++) {printf("%d\n", order[i]);}
		if (c == 10) {return 0;}
	}

	return 0;
}