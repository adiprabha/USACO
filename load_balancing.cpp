// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream read("balancing.in");
    ofstream out("balancing.out");
	int n; read >> n;
	int b; read >> b;
	vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        read >> p[i].first >> p[i].second;
    }
	int min = 10000;
	
    for (const auto& element : p) {
        for (const auto& element1 : p) {
            int i = element.first + 1; 
            int j = element1.second + 1;
            int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
            for (int k = 0; k < n; ++k) {
                if (p[k].first < i && p[k].second < j) {
                    c1++;
                } else if (p[k].first < i && p[k].second > j) {
                    c2++;
                } else if (p[k].first > i && p[k].second < j) {
                    c3++;
                } else if (p[k].first > i && p[k].second > j) {
                    c4++;
                }
            }
			int c5 = max({c1,c2,c3,c4});
			if (c5 < min) {
				min = c5;
			}
	
		}
	}
	out << min;

	

	
}
