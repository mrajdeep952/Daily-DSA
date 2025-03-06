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
    private:
        ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
            if(l1 == nullptr){
                return l2;
            }
            if(l2 == nullptr){
                return l1;
            }
            if(l1->val <= l2->val){
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            }
            else{
                l2->next = mergeTwoLists(l1, l2->next);
                return l2;
            }
        }
    private:
        ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
            ListNode* newhead;
            ListNode* dummy = new ListNode(-1);
            newhead = dummy;
            ListNode* current = dummy;
    
            while (l1 != nullptr && l2 != nullptr) {
                ListNode* newNode = new ListNode();
                current->next = newNode;
    
                if (l1->val < l2->val) {
                    newNode->val = l1->val;
                    l1 = l1->next;
                } else {
                    newNode->val = l2->val;
                    l2 = l2->next;
                }
                current = current->next;
            }
            if(l1 == nullptr)
            current->next = l2;
    
            else
            current->next = l1;
            
            return newhead->next;
        }
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
    
            if (lists.size() == 0) 
            return nullptr;
            
            if (lists.size() == 1)
            return lists[0];
    
            ListNode* newnew;
            newnew = mergeTwoLists(lists[0], lists[1]);
            for( int i = 2; i < lists.size(); i++ ){
                newnew = mergeTwoLists(newnew, lists[i]);
            }
            return newnew;
        }
    };