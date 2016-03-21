#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbers(l1, l2, 0);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry) {
        if(l1 == nullptr) return addNumbers(l2, carry);
        else if(l2 == nullptr) return addNumbers(l1, carry);
        else {
            carry += l1->val + l2->val;
            l1->val = carry % 10;
            l1->next = addTwoNumbers(l1->next, l2->next, carry / 10);
            return l1;
        }
    }
    ListNode* addNumbers(ListNode* l, int carry) {
        if(0 == carry) return l;
        if(nullptr == l) {
            return new ListNode(carry);
        }
        else {
            carry += l->val;
            l->val = carry % 10;
            carry /= 10;
            l->next = addNumbers(l->next, carry);
            return l;
        }
    }
};

int main(int argc, char * const argv[]) {
		
	return 0;
}
