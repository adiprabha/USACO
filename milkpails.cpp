// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream read("pails.in");
    ofstream out("pails.out");
    int X, Y, M;
    read >> X >> Y >> M;
    int max = 0;
    for (int i = 0; i <= M / X; i++) {
        for (int j = 0; j <= M / Y; j++) {
            int sum = X * i + Y * j;
            if (sum > max && sum <= M) {
                max = sum;
            }
        }
    }
    out << max;
    return 0;
}
