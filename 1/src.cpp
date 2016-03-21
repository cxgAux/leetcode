#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        struct Val {
            int x;
            int id;
            Val(int _x, int _id) : x(_x), id(_id) {}
			bool operator<(const Val & val) {
				return this->x < val.x;
			}
        };
		struct Comp {
			bool operator()(const Val & _pre, const Val & _post) {
				return _pre.x < _post.x;
			}
		};
        vector<Val> val;
        for(int i = 0; i < nums.size(); ++ i) {
            val.push_back(Val(nums[i], i));
        }
		Comp comp;
        sort(val.begin(), val.end(), comp);
        for(int i = 0; i < nums.size(); ++ i) {
            int nt = target - val[i].x;
            int l = i + 1, h = nums.size() - 1;
            while(l <= h) {
                int m = (h - l) / 2 + l;
                if(val[m].x == nt) {
                    return vector<int>{min(val[i].id, val[m].id), max(val[i].id, val[m].id)}; 
                }
                else if(val[m].x > nt) {
                    h = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
        }
    }
};

int main(int argc, char * const argv[]) {
	Solution s;
	vector<int> v{3, 2, 1};
	decltype(v) res = s.twoSum(v, 5);
	cout << res[0] << " " << res[1] << endl;
	return 0;
}
