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
    unordered_map<int, int>hash;
    int preIndex = 0;
    
    TreeNode* helper(vector<int>&preorder, vector<int>&inorder, int inStart, int inEnd){
        if(inStart == inEnd) return NULL;
        
        TreeNode* node = new TreeNode(preorder[preIndex]);
        int index = hash[preorder[preIndex]];
        preIndex++;
        
        node->left = helper(preorder, inorder, inStart, index);
        node->right = helper(preorder, inorder, index+1, inEnd);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // storing the index for O(1) lookup
        for(int i = 0; i < inorder.size(); i++){
            hash[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, inorder.size());
    }
};
