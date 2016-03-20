#include <iostream>

using namespace std;

class Solution {
public:
	int minPatches(vector<int>& nums, int n) {
		//i to to deal with special cases like "[], 7" 
		int i = 0, N = nums.size();
		int result = 0;
		long long int element = 1;
		while(element <= n) {
			if(i >= N || nums[i] > element) ｛
				//in this situation, add variable element to double the representable range
				result ++;
				element *= 2;
			} 
			else {
				//it is obvious that range [0, element) can be represented by previous existed/added elements
				element = element + nums[i];
				i ++;
			}
		}
		return result;
	}
};

int  main(int argc, char * const argv[])  {
	return 0;
}																												//                                                                }
																												//                                                                };
