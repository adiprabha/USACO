#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>

int evaluate(int num, int base) {
    vector<int> onedigits;
    onedigits.push_back(num/100 % 10);
	onedigits.push_back(num/10 % 10);
	onedigits.push_back(num % 10);
    return (onedigits[0]) * base * base +
           (onedigits[1]) * base +
           (onedigits[2]);
}

int find(int a, const vector<int>& p) {
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == a) {
            return i;
        }
    }
    return -1;
}

int main() {
    ifstream read("whatbase.in");
    ofstream out("whatbase.out");
    int n;
    read >> n;
    vector<pair<int, int>> p(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        read >> a >> b;
        p[i] = make_pair(a, b);
    }
    for (int i = 0; i < n; i++) {
        vector<int> one;
        vector<int> two;
        for (int j = 10; j <= 15000; j++) {
            int on = evaluate(p[i].first, j);
            int tw = evaluate(p[i].second, j);
            one.push_back(on);
            two.push_back(tw);
            if (find(tw, one) > -1) {
                out << find(tw,one)+10 << " " << j << '\n';
                j = 15001;
            }
            if(find(on, two) > -1) {
                out << j << " " << find(on,two)+10 << '\n';

                j = 15001;

            }
        }
    }
   
}

