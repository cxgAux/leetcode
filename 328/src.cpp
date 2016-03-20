/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return head;
        }
        else {
            ListNode *h1 = head, * lst1 = head, * h2 = head->next, * lst2 = head->next;
            head = head->next->next;
            while(1) {
                lst1->next = head;
                if(head) {
                    head = head->next;
                    lst1 = lst1->next;
                    lst2->next = head;
                    if(head) {
                        head = head->next;
                        lst2 = lst2->next;
                    }
                    else {
                        break;
                    }
                }
                else {
                    break;
                }
            }
            if(lst2->next != nullptr) {
                lst2->next = nullptr;
            }
            lst1->next = h2;
            return h1;
        }
    }
};
