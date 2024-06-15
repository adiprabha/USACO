#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main() {
    ifstream read("gymnastics.in");
    ofstream out("gymnastics.out");
    
    int k, n;
    read >> k >> n;
    
    vector<vector<int>> places(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            read >> places[i][j];
        }
    }
    
    vector<pair<int, int>> z;
    for (int i = 0; i< n; i++) {
        for (int j = i + 1; j < n; j++) {
            z.emplace_back(i,j);
        }
    }
    int total = 0;
    for (const auto& p : z) {
        int c1 = 0;
        int c2 = 0;
        for (int i = 0; i < k; i++) {
            int a = find(places[i].begin(), places[i].end(), p.first + 1) - places[i].begin();
            int b = find(places[i].begin(), places[i].end(), p.second + 1) - places[i].begin();
            if (a < b) {
                c1++;
            } else if (a > b) {
                c2++;
            }
            
        }
        if (c1 == k || c2 == k) {
            total++;
        }
    }
    out << total;


}