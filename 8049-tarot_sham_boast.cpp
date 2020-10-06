#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

int key(string s) {

	int key = 0;
	int size = s.size();	

	for (int i = 0; i<=size-1; i++) {
		int same = 1;
		for (int k = 0; k<size-i; k++) {
			if (s[i+k] != s[k])
				same = 0;
		}
		if (same) {
			//key |= (1<<(size-i-1));
			key += int(pow(3., double(size-i-1)));
		}
	}
	return key;
}

int co_key(string s1, string s2) {

	int co_key = 0;
	int gamma = s1.size();

	for (int i = 0; i<=gamma-1; i++) {
		int same = 1;
		for (int k = 0; k<gamma-i; k++) {
			if (s1[k] != s2[k+i]) {
				same = 0;
			}
		}
		if (same) {
			//co_key |= (1<<(gamma-i-1));
			co_key += int(pow(3., double(gamma-i-1)));
		}
	}	

	return co_key;
}

bool conway(string s1, string s2) {

	int key_s1 = key(s1);
	int key_s2 = key(s2);

	//int co_key12 = co_key(s1, s2);
	//int co_key21 = co_key(s2, s1);


	//float coef12 = ((float)(key_s2 - co_key12))/((float)(key_s1 - co_key21));

	//float prob1 = coef12/(1 + coef12);
	//float prob2 = 1/(1 + coef12);

	//cout << "word1 is: " << s1 << endl;
	//printf("key1 is: %d\n", key_s1);
	//cout << "word2 is: " << s2 << endl;
	//printf("key2 is: %d\n\n", key_s2);

	return key_s1 < key_s2;
}

int main() {

	int n, s;

	while(cin >> n >> s) {

		string strings[s];
		for (int i = 0; i<s; i++)
			cin >> strings[i];

		vector<string> ordered_strings(strings, strings + s);

		sort(ordered_strings.begin(), ordered_strings.end(), conway);

		for (vector<string>::iterator it = ordered_strings.begin(); it != ordered_strings.end(); ++it) {
			cout << *it << endl;
		}
	}
	return 0;
}