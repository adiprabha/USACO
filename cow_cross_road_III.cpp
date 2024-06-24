#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main() {
    ifstream read("cowqueue.in");
    ofstream out("cowqueue.out");

    int n; 
    read >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        read >>a>>b;
        p[i] = make_pair(a,b);
    }
    sort(p.begin(), p.end());

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (count < p[i].first) {
            count = p[i].first + p[i].second;
        } else {
            count += p[i].second;
        }
    }

    out << count;
}
