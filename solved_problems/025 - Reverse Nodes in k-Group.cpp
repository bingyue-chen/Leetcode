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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *record[k], *curr;
        int n;
        curr = head;
        while(curr != NULL){
            n = 0;
            while(n < k && curr != NULL){
                record[n] = curr;
                curr = curr->next;
                n++;
            }
            
            if(n == k){
                for(int i = 0; i < k/2; ++i){
                    swap(record[i]->val, record[k-1-i]->val);
                }
            }
        }
        return head;
    }
};