#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> res(num + 1, 0);
		for(int i = 1; i <= num; ++ i) {
			res[i] = res[i & (i - 1)] + 1;
		}
		return res;
	}
};

int main(int argc, char * const argv[]) {
	Solution s;
	auto res = s.countBits(5);
	for(auto & x : res) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
