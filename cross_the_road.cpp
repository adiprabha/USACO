#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	ifstream read("circlecross.in");
    ofstream out("circlecross.out");
	string s; read>>s;
	int count = 0;
    for (int i = 0; i < 52; i++) {
        for (int j = i + 1; j < 52; j++) {
            if (s[i] == s[j]) {
                for (int k = i + 1; k < j; k++) {
                    char c = s[k];
                    string s1 = s.substr(k+1);
                    for (int b = i+1; b < 52; b++) {
                        if (s[b] == c) {
                            if (b > j) {
                                count++;
                            }
                        }   
                    }
                }
            }
        }
    }
    out << count;
}
