#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isSelfCrossing(vector<int>& x) {			
		int sz = x.size();
		for(int i = 0; i < sz; ++ i) {
			//3 situations
			if(i >= 3 && x[i] >= x[i - 2] && x[i - 1] <= x[i - 3]) {
				return true;										
			}
			else if(i>= 4 && x[i-1]==x[i-3] && x[i]+x[i-4]>=x[i-2] ) {
				return true;
			}
			else if(i >= 5 && (x[i] + x[i - 4] >= x[i - 2]) && (x[i - 1] + x[i - 5] >= x[i - 3]) && x[i - 2] >= x[i - 4] && x[i - 3] >= x[i - 1]) {
				return true;
			}
		}
		return false;
	}
};

int main(int argc, char * const argv[]) {
	return 0;
}
