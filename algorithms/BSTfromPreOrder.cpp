#include <vector>
#include <climits>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    TreeNode* build(vector<int>& pre, int& i, int min, int max) {
    if (i >= pre.size() || pre[i] <= min || pre[i] >= max)
        return nullptr;

    TreeNode* root = new TreeNode(pre[i++]);
    root->left  = build(pre, i, min, root->val);
    root->right = build(pre, i, root->val, max);
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int index=0;
        return build(preorder, index, INT_MIN, INT_MAX);
        
    }
};