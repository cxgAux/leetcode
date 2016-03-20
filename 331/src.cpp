class Solution {
public:
	const string delimiter = "#";
	const char parter = ',';
	bool isValidSerialization(string preorder) {
		vector<string> pre;
		size_t i = 0, j = i;
		for(; i < preorder.size();) {
			j = preorder.find_first_of(parter, i);
			if(j != string::npos) {
				pre.push_back(preorder.substr(i, j - i));
				i = j + 1;
			}
			else
			{
				break;
			}
		}
		pre.push_back(preorder.substr(i));
		return isValidSerialization(pre);
	}
	bool isValidSerialization(vector<string> preorder) {
		int sz = preorder.size();
		if(sz == 0) {
			return true;
		}
		else if(preorder[0] == "#") {
		    return sz == 1;
		} 
		else if(sz % 2 == 0) {
		    return false;
		}
		else {
			queue<int> q;
			q.push(0);
			int iter = 1, l, r;
			while(! q.empty()) {
				q.pop();
				l = iter ++;
				r = iter ++;
				if(r < sz) {
					if(preorder[l] != delimiter) {
						q.push(l);
					}
					if(preorder[r] != delimiter) {
						q.push(r);
					}
				}
				else {
					return false;
				}
			}
			return r == sz - 1;
		}
	}
};
