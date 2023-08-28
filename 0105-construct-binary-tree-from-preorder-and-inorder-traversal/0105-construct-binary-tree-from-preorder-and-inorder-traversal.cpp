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
  void createMap(vector<int> &inorder, int n,  unordered_map<int,int> &mp){
    for(int i=0; i<n; i++){
      mp[inorder[i]] = i;
    }
  }
  TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &idx, int s, int e, unordered_map<int,int> &mp, int n){
    if(idx>=n || s>e) return NULL;
    int element = preorder[idx++];
    int pos = mp[element];
    TreeNode* node = new TreeNode(element);
    node->left = solve(preorder,inorder,idx,s,pos-1,mp,n);
    node->right = solve(preorder,inorder,idx,pos+1,e,mp,n);
    return node;
  }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
      unordered_map<int,int> mp;
      createMap(inorder,n,mp);
      int pidx = 0;
      TreeNode* ans = solve(preorder,inorder,pidx,0,n-1,mp,n);
      return ans;
    }
};