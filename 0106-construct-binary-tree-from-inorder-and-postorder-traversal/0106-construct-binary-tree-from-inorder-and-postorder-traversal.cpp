class Solution {
public:
void createmap(vector<int> &inorder, unordered_map<int,int> &mp, int n){
    for(int i=0; i<n; i++) mp[inorder[i]] = i;
}
TreeNode* solve(vector<int> &inorder, vector<int> &postorder, int &idx, int pstart, int pend, int n, unordered_map<int,int> &mp){
    if(idx<0 || pstart>pend) return NULL;
    // reverse(postorder.begin(),postorder.end());
    int element = postorder[idx--];
    TreeNode* node = new TreeNode(element);
    int pos = mp[element];
    node->right = solve(inorder,postorder,idx,pos+1,pend,n,mp);
    node->left = solve(inorder,postorder,idx,pstart,pos-1,n,mp);
    return node;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        int n = inorder.size();
        createmap(inorder,mp,n);
        // reverse(postorder.begin(),postorder.end());
        int rootindex = n-1;
        TreeNode* ans = solve(inorder,postorder,rootindex,0,n-1,n,mp);
        return ans;
    }
};