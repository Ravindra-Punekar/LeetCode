/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode* temp = head;
        int len = 0;
        
        while(temp){
            len++;
            temp = temp->next;
        }
        temp = head;

        if(len<k){
            while(temp){
                ListNode* t = temp;
                temp = temp->next;
                t->next = NULL;
                ans.push_back(t);
            }
            while(k-len){
                ans.push_back(NULL);
                k--;
            }
        }
        else{
            int size = len/k; 
            int extra = len%k; 
            while(len){ 
                int n = size; 
                if(extra){
                    n++;
                    extra--;
                }  
                ListNode* dummy = new ListNode(-1);
                ListNode* curr = dummy;

                while(n-- && head){
                    curr->next=new ListNode(temp->val);
                    temp=temp->next;
                    curr=curr->next;
                    len--;
                }
                ans.push_back(dummy->next);
            }
        }
        return ans;
    }
};