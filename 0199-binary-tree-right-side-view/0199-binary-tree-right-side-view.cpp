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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
      if(root==NULL) return ans;
      map<int,int> mp;
      queue<pair<TreeNode*,int>> q;
      q.push({root,0});
      while(!q.empty()){
        pair<TreeNode*,int> p = q.front();
        q.pop();
        TreeNode* temp = p.first;
        int hd = p.second;
        mp[hd] = temp->val;
        if(temp->left!=NULL) q.push({temp->left,hd+1});
        if(temp->right!=NULL) q.push({temp->right,hd+1});
      }
      for(auto i: mp) ans.push_back(i.second);
      return ans;
    }
};