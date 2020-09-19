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
    
    int findPath(TreeNode* root, int& maxi){
        if(!root)
            return 0;
        int left  = findPath(root->left,  maxi);
        int right = findPath(root->right, maxi);
        left  = max(0, left);
        right = max(0, right);
        
        if(left + right + root->val > maxi)
            maxi = root->val + left + right;
        return max(root->val + left, root->val + right);
    }
    
    
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findPath(root, maxi);
        return maxi;
    }
};
