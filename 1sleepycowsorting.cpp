#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>

int main() {
	ifstream read("sleepy.in");
    ofstream out("sleepy.out");
	int n; read >> n;
	vector<int> nums;
	for(int i = 0; i < n; i++) {
		int a; read >> a;
		nums.push_back(a);
	}
	int count = 0;
	for (int j = nums.size()-1; j > 0; j--) {
		if (nums[j] > nums[j-1]) {
			count++;
		} else { 
			j = 0;
		}

	}
	out << (nums.size() - count-1);
}
