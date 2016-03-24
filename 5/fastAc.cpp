#include <iostream>
#include <string>

using namespace std;

//more intuitive way

class Solution {
public:
	string longestPalindrome(string s) {
		if(s.size() < 2) {
			return s;
		}
		int _len = 1, _idx = 0, sz = s.size();
		for(int i = 0; i < sz - _len / 2; ++ i) {
			int k = i, j = k, curLen = 1;
			while(k < sz - 1 && s[k] == s[k + 1]) {
			    curLen ++;
			    k ++;
			}
			do { 
				--j;
				++k;
				curLen += 2;
			}while(j >= 0 && k < sz && s[j] == s[k]);
			curLen -= 2;
			if(_len < curLen) {
				_len = curLen;
				_idx = j + 1;
			}		
		}
		return s.substr(_idx, _len);
	}
};

int main(int argc, char * const argv[]) {
	return 0;
}

