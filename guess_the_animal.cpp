#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main() {
    ifstream read("guess.in");
    ofstream out("guess.out");
    int n;
    read >> n;
    vector<string> animal;
    vector<vector<string>> characteristics(n);
    
    for (int i = 0; i < n; ++i) {
        string name;
        read >> name;
        animal.push_back(name);
        int k;
        read >> k;
        for (int j = 0; j < k; ++j) {
            string characteristic;
            read >> characteristic;
            characteristics[i].push_back(characteristic);
        }
    }
    int max_shared = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int count = 0;
            for (int k = 0; k < characteristics[i].size(); k++) {
                for (int w = 0; w < characteristics[j].size(); w++) {
                    if (characteristics[i][k] == characteristics[j][w]) {
                        count++;
                    }
                }
            }
            if (count > max_shared) {
                max_shared = count;
            }
        }
    }
    out << max_shared + 1;
}
