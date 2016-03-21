#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool comp(const string & _pre, const string & _post) {
    return _pre.size() > _post.size();
}

class Solution {
public:
    int fc2b(string & s) {
        int bits = 0;
        for(auto & x : s) {
            bits |= (1 << (x - 'a'));
            if(bits == 0x3FFFFFF) {
                break;
            }
        }
        return bits;
    }
    
    int maxProduct(vector<string>& words) {
        int sz = words.size(), c2b[sz], lens[sz];
        sort(words.begin(), words.end(), comp);// improve 4ms
        for(int i = 0; i < sz; ++ i) {
            c2b[i] = fc2b(words[i]);
            lens[i] = words[i].size();
        }
        
        int maxV = 0;
        for(int i = 0; i < sz; ++ i) {
            if(sqrt(maxV) >= lens[i]) {// possiblly improve little, but its cost is comparable to its improvement
                    break;
            }
            for(int j = i + 1; j < sz; ++ j) {
                if(0 == (c2b[i] & c2b[j])) {
                    maxV = max(maxV, lens[i] * lens[j]);
                    break;
                }
            }
        }
        return maxV;
    }
};

int main(int argc, char * const argv[]) {
	Solution s;
	vector<string> v{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
	cout << s.maxProduct(v) << endl;
	return 0;
}
