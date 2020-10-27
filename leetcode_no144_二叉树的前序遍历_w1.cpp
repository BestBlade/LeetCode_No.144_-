/* ------------------------------------------------------------------|
给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,2,3]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	迭代法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：8.5 MB, 在所有 C++ 提交中击败了38.36%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};


vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;

    if (root == NULL) {
        return res;
    }

    stack<TreeNode *> nodestk;
    TreeNode* nowNode = root;

    while (!nodestk.empty() || nowNode != NULL) {
        while (nowNode != NULL) {
            res.emplace_back(nowNode->val);                 /*  emplace_back要优于push_back,但是只在C++11之后可以使用    */
            nodestk.emplace(nowNode);
            nowNode = nowNode->left;
        }
        nowNode = nodestk.top();                            /*  取出上一个节点 */
        nodestk.pop();                                      /*  出栈  */

        nowNode = nowNode->right;                           /*  遍历右子树   */
    }
    
    return res;
}
