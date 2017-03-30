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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sumList, *current, *newNode;
        int carry;
        sumList = new ListNode((l1->val + l2->val) % 10);
        carry = (l1->val + l2->val) / 10;
        current = sumList;
        l1 = l1->next;
        l2 = l2->next;
        while(!(l1 == NULL && l2 == NULL)){
            newNode = new ListNode(-1);
            if(l1 == NULL){
                newNode->val = (l2->val + carry) % 10;
                carry = (l2->val + carry) / 10;
                l2 = l2->next;
            }
            else if(l2 == NULL){
                newNode->val = (l1->val + carry) % 10;
                carry = (l1->val + carry) / 10;
                l1 = l1->next;
            }
            else{
                newNode->val = (l1->val + l2->val + carry) % 10;
                carry = (l1->val + l2->val + carry) / 10;
                l1 = l1->next;
                l2 = l2->next;
            }
            current->next = newNode;
            current = newNode;
        }
        while(carry > 0){
            newNode = new ListNode(carry % 10);
            carry = carry / 10;
            current->next = newNode;
            current = newNode;
        }
        return sumList;
    }
};