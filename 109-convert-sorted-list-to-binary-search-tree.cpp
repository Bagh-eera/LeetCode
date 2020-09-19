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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(!head)
            return NULL;
        
        ListNode* prevptr = NULL;
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        
        while(fastptr && fastptr->next) {
            prevptr = slowptr;
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        
        if(prevptr)
            prevptr->next = NULL;
        
        TreeNode* root = new TreeNode(slowptr->val);
        root->left  = sortedListToBST(head);
        root->right = sortedListToBST(slowptr->next);
        return root;      
    }
};