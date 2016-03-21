#include <iostream>
#include <cmath>


using namespace std;

class Solution {
public:
	int bulbSwitch(int n) {
		return sqrt(n);
	}
};

int main(int argc, char * const argv[]) {
	Solution s;
	cout << s.bulbSwitch(1001) << endl;
	return 0;
}
