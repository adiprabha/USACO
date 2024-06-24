#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> p;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    p.push_back(x);
  }
  sort(p.begin(),p.end());
  int count = 1;
  int count1 = 1;
  for (int i = 1; i < n; i++) {
    if (p[i] == p[i-1]) {
      count1++;
    } else {
      count++;
    }
  }
  cout << count;
}