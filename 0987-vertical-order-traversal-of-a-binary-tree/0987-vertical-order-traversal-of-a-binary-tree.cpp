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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
      map<int, map<int, vector<int> > > mp;
      queue<pair<TreeNode*,pair<int,int> > > q;
      q.push({root,{0,0}});
      while(!q.empty()){
        pair<TreeNode*,pair<int,int>> t = q.front();
        q.pop();
        TreeNode* firstNode = t.first;
        int hd = t.second.first;
        int lv = t.second.second;
        mp[hd][lv].push_back(firstNode->val);
        if(firstNode->left) q.push({firstNode->left,{hd-1,lv+1}});
        if(firstNode->right) q.push({firstNode->right,{hd+1,lv+1}});
      }
      for(auto i: mp){
        vector<int> t;
        for(auto j: i.second){
          sort(j.second.begin(),j.second.end());
          for(auto k: j.second) t.push_back(k);
        }
        ans.push_back(t);
      }
      return ans;
    }
};