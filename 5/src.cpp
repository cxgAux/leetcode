#include <iostream>
#include <string>
#include <vector>

using namespace std;

//very intuitive ways uisng Manchester Algortihm

class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        if(sz < 2) {
            return s;
        }
        else {
            int nsz = 2 * sz + 1;
            string news = "#";
            vector<int> count(nsz, 0);
            for(int i = 0; i < sz; ++ i) {
                news.push_back(s[i]);
                news.push_back('#');
            }
            int maxId = 0, maxLen = 0;
            for(int i = 1; i < nsz; ++ i) {
                int l = i - count[i], h = i + count[i];
                do {--l; ++ h;} while(l >= 0 && h < nsz && news[l] == news[h]);
                count[i] = min(i - l - 1, h - i - 1);
                for(int j = 1; j <= count[i]; ++ j) {
                    count[i + j] = min(count[i - j], count[i] - j - 1);
                }
                if(maxLen < count[i]) {
                    maxLen = count[i];
                    maxId = i;
                }
            }
            return s.substr((maxId - maxLen) / 2, maxLen);
        }
    }
};

int main(int argc, char * const argv[]) {
	return 0;
}
