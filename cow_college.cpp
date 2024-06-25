#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<long long> p(n);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		p[i] = x;
	}
	sort(p.begin(), p.end());
	long long max = 0;
	int min = 0;
	for (int i = 0; i < n; i++) {
		if (p[i]*(n-i) > max) {
			max = p[i]*(n-i);
			min = p[i];

		}
	}
	cout << max;
	cout << " ";
	cout << min;
}
