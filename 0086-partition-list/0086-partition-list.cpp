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
    ListNode* partition(ListNode* head, int x) {
        vector<int> small;
      vector<int> large;
      ListNode* temp = head;
      while(temp!=NULL){
        if(temp->val<x){
          small.push_back(temp->val);
        }
        else large.push_back(temp->val);
        temp = temp->next;
      }
      ListNode* newNode = new ListNode();
      ListNode* ptr = newNode;
      for(int i=0; i<small.size(); i++){
        ListNode* node = new ListNode(small[i]);
        ptr->next = node;
        ptr = ptr->next;
      }
      for(int i=0; i<large.size(); i++){
        ListNode* node = new ListNode(large[i]);
        ptr->next = node;
         ptr = ptr->next;
      }
      return newNode->next;
    }
};