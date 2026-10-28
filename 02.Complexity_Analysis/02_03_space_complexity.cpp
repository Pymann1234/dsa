#include <cstddef>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct LinkedNode {
    int value;
    unique_ptr<LinkedNode> next;

    explicit LinkedNode(int nodeValue) : value(nodeValue), next(nullptr) {}
};

struct TreeNode {
    int value;
    unique_ptr<TreeNode> left;
    unique_ptr<TreeNode> right;

    explicit TreeNode(int nodeValue) : value(nodeValue), left(nullptr), right(nullptr) {}
};

int constantSpaceExample(int n) {
    int total = 0;
    for (int i = 0; i < n; ++i) {
        total += i % 2;
    }
    return total;
}

int linearSpaceExample(int n) {
    vector<int> values(n, 1);
    vector<string> labels;
    unordered_map<int, string> lookup;
    labels.reserve(n);
    lookup.reserve(n);

    auto first = make_unique<LinkedNode>(0);
    LinkedNode* tail = first.get();
    for (int i = 0; i < n; ++i) {
        labels.push_back(to_string(i));
        lookup.emplace(i, labels.back());
        if (i > 0) {
            tail->next = make_unique<LinkedNode>(static_cast<int>(i));
            tail = tail->next.get();
        }
    }

    return static_cast<int>(values.size() + labels.size() + lookup.size()) + n;
}

int linearRecursionDepth(int n) {
    if (n == 0) {
        return 0;
    }
    return 1 + linearRecursionDepth(n - 1);
}

int quadraticSpaceExample(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    return static_cast<int>(matrix.size() * (n == 0 ? 0 : matrix.front().size()));
}

int quadraticRecursiveSpace(int n) {
    if (n == 0) {
        return 0;
    }
    vector<int> localValues(n, 0);
    return static_cast<int>(localValues.size()) + quadraticRecursiveSpace(n - 1);
}

unique_ptr<TreeNode> buildFullTree(int levels) {
    if (levels == 0) {
        return nullptr;
    }
    auto root = make_unique<TreeNode>(static_cast<int>(levels));
    root->left = buildFullTree(levels - 1);
    root->right = buildFullTree(levels - 1);
    return root;
}

int countTreeNodes(const TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countTreeNodes(root->left.get()) + countTreeNodes(root->right.get());
}

int logarithmicRecursionDepth(int n) {
    if (n <= 1) {
        return 0;
    }
    return 1 + logarithmicRecursionDepth(n / 2);
}

int main() {
    int n = 0;
    if (!(cin >> n) || n < 0) {
        cerr << "Enter a non-negative integer.\n";
        return 1;
    }
    if (n > 1000) {
        cerr << "Use n <= 1000 to keep recursive examples safe.\n";
        return 1;
    }

    cout << "Constant-extra-space result: " << constantSpaceExample(n) << '\n';
    cout << "Elements stored by linear-space example: "
              << linearSpaceExample(n) << '\n';
    cout << "Linear recursion depth: " << linearRecursionDepth(n) << '\n';
    cout << "Elements in quadratic matrix: " << quadraticSpaceExample(n) << '\n';
    cout << "Elements across quadratic recursive frames: "
              << quadraticRecursiveSpace(n) << '\n';
    cout << "Logarithmic recursion depth: " << logarithmicRecursionDepth(n) << '\n';

    if (n <= 15) {
        const auto tree = buildFullTree(n);
        cout << "Nodes in full binary tree: " << countTreeNodes(tree.get()) << '\n';
    } else {
        cout << "Full binary tree example skipped for n > 15.\n";
    }
}
