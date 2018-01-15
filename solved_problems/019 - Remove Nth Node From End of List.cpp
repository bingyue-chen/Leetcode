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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *temp = head, *delete_node_prev = head;
        int n_t = n;
        
        while(n_t--){
            temp = temp->next;
        }
        
        // delete head case
        if(temp == NULL){
            return head->next;
        }
        
        // delete not head case
        while(temp->next != NULL){
            temp = temp->next;
            delete_node_prev = delete_node_prev->next;
        }
        
        delete_node_prev->next = delete_node_prev->next->next;
        
        return head;
    }
};