#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<cstdint>
#include<math.h>
#include<algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;


int main() {

	int nbCases = 1;
	int n;

	while (scanf("%d\n", &n) == 1) {
		
		if (n == 0) return 0;
		// input
		int box_corners[6]; //two opposite corners of the box
		int x_coords[n], y_coords[n], z_coords[n];
		double radius[n];

 		scanf("%d %d %d\n", &box_corners[0], &box_corners[1], &box_corners[2]);
		scanf("%d %d %d\n", &box_corners[3], &box_corners[4], &box_corners[5]);

		for (int i = 0; i<n; i++) {
			scanf("%d %d %d\n", &x_coords[i], &y_coords[i], &z_coords[i]);
		}

		int endTest;
		scanf("%d\n", &endTest);

		int p[n];
		for (int i = 0; i<n; i++)
			p[i] = i;
 	
		double cube_volume = abs(box_corners[3] - box_corners[0])*
				     abs(box_corners[4] - box_corners[1])*
			             abs(box_corners[5] - box_corners[2]);

		double unoccupied_volume = cube_volume;

		double max_radius = 1e9;

		radius[0] = max_radius;
		radius[0] = min(radius[0], double(abs(x_coords[0] - box_corners[0])));
		radius[0] = min(radius[0], double(abs(x_coords[0] - box_corners[3])));
		radius[0] = min(radius[0], double(abs(y_coords[0] - box_corners[1])));
		radius[0] = min(radius[0], double(abs(y_coords[0] - box_corners[4])));
		radius[0] = min(radius[0], double(abs(z_coords[0] - box_corners[2])));
		radius[0] = min(radius[0], double(abs(z_coords[0] - box_corners[5])));
	

		do {
			double current_unoccupied_volume = cube_volume;
			current_unoccupied_volume -= (4./3.)*M_PI*radius[0]*radius[0]*radius[0];

			for (int k = 1; k<n; k++) { // we compapre each point with the boundaries and 
				double current_radius = max_radius;
			
				int l = k-1;
				while (l >= 0) {
					double tmp = 0;
					if (l < k) {
						int tmp = (x_coords[k] - x_coords[l])*(x_coords[k] - x_coords[l]) + 
							  (y_coords[k] - y_coords[l])*(y_coords[k] - y_coords[l]) + 
					        	  (z_coords[k] - z_coords[l])*(z_coords[k] - z_coords[l]);
						double tmp2 = sqrt(tmp);
						current_radius = min(current_radius, tmp2 - radius[l]);
					}
					l--;
				}
				current_radius = min(current_radius, double(abs(x_coords[k] - box_corners[0])));
				current_radius = min(current_radius, double(abs(x_coords[k] - box_corners[3])));
				current_radius = min(current_radius, double(abs(y_coords[k] - box_corners[1])));
				current_radius = min(current_radius, double(abs(y_coords[k] - box_corners[4])));
				current_radius = min(current_radius, double(abs(z_coords[k] - box_corners[2])));
				current_radius = min(current_radius, double(abs(z_coords[k] - box_corners[5])));
				
				radius[k] = current_radius;			
			
				current_unoccupied_volume -= (4./3.)*M_PI*radius[k]*radius[k]*radius[k];
			}
			unoccupied_volume = min(unoccupied_volume, current_unoccupied_volume);

		} while(next_permutation(p, p+n));

		printf("\n");
		printf("Box %d: %d\n\n", nbCases, int(unoccupied_volume)+1);
		nbCases++;
	}

	return 0;

}