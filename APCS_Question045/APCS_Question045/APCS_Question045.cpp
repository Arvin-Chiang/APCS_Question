#include <iostream>
#include <vector>
using namespace std;

// 節點定義
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 插入
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// 計算高度
int getHeight(Node* root) {
    if (!root) return 0;
    int leftH = getHeight(root->left);
    int rightH = getHeight(root->right);
    return max(leftH, rightH) + 1;
}

int main() {
    vector<int> nums;
    int x;
    while (cin >> x) {
        nums.push_back(x);
    }

    Node* root = nullptr;
    for (int val : nums) {
        root = insert(root, val);
    }

    cout << getHeight(root) << endl;

    return 0;
}
