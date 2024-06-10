#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main() {
    ifstream read("lifeguards.in");
    ofstream out("lifeguards.out");
    int n;
    read >> n;
    vector<pair<int, int>> p;
    int newarray[1001] = {0};

    // Reading the intervals and marking the times in newarray
    for (int i = 0; i < n; ++i) {
        int l, r;
        read >> l >> r;
        for (int j = l; j < r; ++j) {
            newarray[j]++;
        }
        p.push_back({l, r});
    }

    int maxCoverage = 0;

    // Calculate the maximum coverage
    for (int i = 0; i < n; ++i) {
        int tempArray[1001];
        memcpy(tempArray, newarray, sizeof(newarray)); // Copy newarray to tempArray

        // Remove the current lifeguard's shift
        for (int j = p[i].first; j < p[i].second; ++j) {
            tempArray[j]--;
        }

        // Calculate the coverage without the current lifeguard
        int ct = 0;
        for (int j = 0; j < 1001; ++j) {
            if (tempArray[j] > 0) {
                ct++;
            }
        }

        if (maxCoverage < ct) {
            maxCoverage = ct;
        }
    }

    out << maxCoverage << endl;

    return 0;
}
