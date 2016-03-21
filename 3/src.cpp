#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sz = s.size();
        if(sz < 2) return sz;
        else {
            vector<int> pos(256, -1);
            int cur = 0, len = 0;
            for(int i = 0; i < sz; ++ i) {
                if(pos[s[i]] == -1) {
                    pos[s[i]] = i;
                    cur += 1;
                }
                else {
                    cur = min(cur + 1, i - pos[s[i]]);
                    pos[s[i]] = i;
                }
                len = max(cur, len);
            }
            return len;
        }
    }
};

int main(int argc, char * const argv[]) {
	return 0;
}
