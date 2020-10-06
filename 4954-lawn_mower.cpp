#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<cstdint>

using namespace std;

int main() {
    int nx, ny;
    double w;

    int c;    

    while (true) {
	c = 0;
	scanf("%d %d %lf", &nx, &ny, &w);
	if (nx == 0 && ny == 0 & w == 0.0) {return 0;}

	double x_passes[nx], y_passes[ny];
    
	for (int i = 0; i < nx; i++) {
		scanf("%lf", &x_passes[i]);
	}
	for (int j = 0; j < ny; j++) {
		scanf("%lf", &y_passes[j]);
	}

    	double x;
    	int k;
    	for (int i = 1; i < nx; i++) {
		x = x_passes[i];
        	k = i - 1;
		while (k >= 0 && x_passes[k] > x) {
	    		x_passes[k+1] = x_passes[k];
	    		k--;
		}
		x_passes[k+1] = x;
    	}

    	double y;
    	int l;
    	for (int i = 1; i < ny; i++) {
		y = y_passes[i];
        	l = i - 1;
		while (l >= 0 && y_passes[l] > y) {
	    		y_passes[l+1] = y_passes[l];
	    		l--;
		}
		y_passes[l+1] = y;
    	}

    	for (int i = 0; i < nx-1; i++) {
		if ((x_passes[i+1] - x_passes[i] > w) && (c == 0)) {c++; printf("NO\n"); break;}
    	}
    	for (int i = 0; i < ny-1; i++) {
		if ((y_passes[i+1] - y_passes[i] > w) && (c == 0)) {c++; printf("NO\n"); break;}
    	}

    	if ((x_passes[0] > w/2) && (c == 0)) {c++; printf("NO\n");}
    	if ((x_passes[nx-1] + w/2 < 75.0) && (c == 0)) {c++; printf("NO\n");}
    	if ((y_passes[0] > w/2) && (c == 0)) {c++; printf("NO\n");}
    	if ((y_passes[ny-1] + w/2 < 100.0) && (c == 0)) {c++; printf("NO\n");}

    	if (c == 0) {printf("YES\n");}
    }

    return 0;	
}