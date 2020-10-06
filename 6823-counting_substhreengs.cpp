#include<iostream>
#include<string>

using namespace std;

int main() {

	unsigned int MAX_LETTER = 1e6;
	
	while(true) {
		char input[MAX_LETTER];
		cin >> input; //scanf("%s\n", &input);
		if (input == "") return 0;

		unsigned int size = 0;
		while (input[size] != 0) {
			size++;
		}

		int numbers[size];
		for (int i = 0; i<size; i++) {
			numbers[i] = input[i] - 48;
		}

		int count = 0;

		for (int i = 0; i<size; i++) {
			int j = i;
			while (numbers[j] <= 9 && j != size) {
				int digits_sum = 0;
				for (int k = i; k<=j; k++) {
					digits_sum += numbers[k];
				}
				if (digits_sum%3 == 0) {
					count++;
				}

				j++;
			}
		}
		printf("%d\n", count);
	}

	return 0;
}