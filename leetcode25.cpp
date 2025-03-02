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
        ListNode* reverseList(ListNode* head) {
            
            ListNode* prev = nullptr;
            ListNode* temp = head;
            while(temp != nullptr){
                ListNode* front = temp->next;
                temp->next = prev;
                prev = temp;
                temp = front;
            }
            return prev;
        }
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            
            ListNode* dummy = new ListNode(-1);
            dummy->next = head;
            ListNode* curr = head;
            ListNode* prev = dummy;
            while(curr != nullptr){
                int groupCount = 1;
                ListNode* temp = curr;
                while(curr != nullptr && groupCount < k && curr->next != nullptr){
                    curr = curr->next;
                    groupCount++;
                }
                if(groupCount == k){
                    ListNode* nextNode = curr->next;
                    curr->next = nullptr;
                    ListNode* newHead = reverseList(temp);
                    prev->next = newHead;
                    temp->next = nextNode;
                    prev = temp;
                    curr = nextNode;
                }
                else break;
            }
            return dummy->next;
        }
    };