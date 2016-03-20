#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
	bool increasingTriple(vector<int> & nums) {
		int sz = nums.size();
		if(sz < 3) {
			return false;
		}
		else {
			int max1 = nums[0], max2 = INT_MAX;
			for(int i = 1; i < sz; ++ i) {
				if(nums[i] > max2) {
					return true;
				}
				else {
					if(nums[i] > max1) {
						max2 = nums[i];
					}
					else {
						max1 = nums[i];
					}
				}
			}
			return false;
		}
	}
};

int main(int argc, char * const argv[]) {
	return 0;
}
