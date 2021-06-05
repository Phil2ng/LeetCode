// BST二叉搜索树的性质, DFS

class Solution
{
public:
    Node *treeToDoublyList(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

private:
    Node *pre, *head;
    void dfs(Node *cur)
    {
        if (cur == nullptr)
            return;
        dfs(cur->left);

        if (pre != nullptr)
        {
            pre->right = cur;
            cur->left = pre;
        }
        else
            head = cur;
        pre = cur;

        dfs(cur->right);
    }
};
