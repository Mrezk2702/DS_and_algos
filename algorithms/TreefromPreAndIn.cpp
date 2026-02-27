 #include <vector>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            if(preorder.empty()||inorder.empty())
    {
        return nullptr;
    }
    int rootVal=preorder[0];
    TreeNode*root=new TreeNode(rootVal);
    int rootIDX=0;
    for(int i=0;i<inorder.size();i++)
    {
        if(inorder[i]==rootVal)
        {
            rootIDX=i;
            break;
        }
    }
    vector<int>leftInorder(inorder.begin(),inorder.begin()+rootIDX);
    vector<int>rightInorder(inorder.begin()+rootIDX+1,inorder.end());
    vector<int>leftPreorder(preorder.begin()+1,preorder.begin()+1+leftInorder.size());
    vector<int>rightPreorder(preorder.begin()+1+leftInorder.size(),preorder.end());
    root->left=buildTree(leftPreorder,leftInorder);
    root->right=buildTree(rightPreorder,rightInorder);
    return root;

    }
};