#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream read("cownomics.in");
    ofstream out("cownomics.out");
	int n; read >> n;
	int m; read >> m;
	vector<string> arr;
	for (int i = 0; i < 2*n; i++) {
		string s; read >> s;
		arr.push_back(s);
	}
	int count = 0;
	for (int i = 0; i < m; i++) {
		vector<char> a1;
		vector<char> a2;
		for (int j = 0; j < n; j++) {
			a1.push_back(arr[j][i]);
            a2.push_back(arr[j+n][i]);
		}
		vector<char> a3;
		for (int w = 0; w < n; w++) {
			for (int z = 0; z <n; z++) {
				if (a1[w] == a2[z]) {
					a3.push_back(a1[w]);
				}
			}
		}
		if (a3.size() == 0) {
			count++;
		}
	}

	out << count;
}
