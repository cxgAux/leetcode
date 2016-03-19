#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode * left, * right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	int rob(TreeNode * root) {
		if(root == nullptr) {
			return 0;
		}
		else {
			int  y = 0, n = 0;
			rob(root, y, n);
			return max(y, n);
		}
	}

	void rob(TreeNode * root, int & self, int & nonself) {
		if(root) {
			int y1 = 0, y2 = 0, n1 = 0, n2 = 0;
			rob(root->left, y1, n1);
			rob(root->right, y2, n2);
			self = root->val + n1 + n2;
			nonself = max(y1, n1) + max(y2, n2);
		}
		else {
			self = nonself = 0;
		}
	}
};

int main(int argc, char * const argv[]) {

	return 0;
}
