#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr)
        return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int getHeight(TreeNode* root) {
    if (root == nullptr) return 0;
    int leftH = getHeight(root->left);
    int rightH = getHeight(root->right);
    return max(leftH, rightH) + 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    TreeNode* root = nullptr;
    for (int val : nums)
        root = insert(root, val);

    cout << getHeight(root) << endl;

    return 0;
}
