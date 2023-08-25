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
  void fun(TreeNode* root, string s, vector<string> &ans){
    if(!root) return ;
    if(!root->left && !root->right) {ans.push_back(s);
                                    return ;}
    if(root->left) fun(root->left,s + "->" + to_string(root->left->val),ans);
    if(root->right) fun(root->right,s + "->" + to_string(root->right->val),ans);
    
  }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
      if(root==NULL) return ans;
      fun(root,to_string(root->val),ans);
      return ans;
    }
};