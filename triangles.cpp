#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream read("lifeguards.in");
    ofstream out("lifeguards.out");

    int n;
    read >> n;

    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        read >> p[i].first >> p[i].second;
    }

    int max = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                int area = 0;
                if (p[k].first == p[i].first && p[k].second == p[j].second) {
                    area = abs(p[j].first - p[i].first) * abs(p[j].second - p[i].second);
                } else if (p[k].second == p[i].second && p[k].first == p[j].first) {
                    area = abs(p[j].second - p[i].second) * abs(p[j].first - p[i].first);
                }
                if (max < area) {
                    max = area;
                }
            }
        }
    }

    out << max << endl;
    cout << max << endl;

    return 0;
}
