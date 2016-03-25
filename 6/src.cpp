#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int sz = s.size();
        string res;
        int jump = 2 * (numRows - 1);
        for(int l = 0, h = jump; l <= h; ++ l, -- h) {
            if(l == h || l == 0) {
                for(int j = l; j < sz; j += jump) {
                    res.push_back(s[j]);
                }
            }
            else {
                for(int j = l, k = h; j < sz; j += jump, k += jump) {
                    res.push_back(s[j]);
                    if(k < sz) {
                        res.push_back(s[k]);
                    }
                }
            }
        }
        return res;
    }
};


int main(int argc, char * const argv[]) {
}
