#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Verified Solution for Exercise 6.1: Binary Search Tree
struct BSTNode {
    int val;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root_(nullptr), size_(0) {}

    ~BinarySearchTree() {
        destroy(root_);
    }

    bool insert(int val) {
        if (!root_) {
            root_ = new BSTNode(val);
            size_++;
            return true;
        }
        return insertHelper(root_, val);
    }

    bool search(int val) const {
        BSTNode* curr = root_;
        while (curr) {
            if (val == curr->val) return true;
            if (val < curr->val) curr = curr->left;
            else curr = curr->right;
        }
        return false;
    }

    vector<int> inOrderTraversal() const {
        vector<int> res;
        inOrderHelper(root_, res);
        return res;
    }

    int findMin() const {
        if (!root_) throw runtime_error("Tree is empty");
        BSTNode* curr = root_;
        while (curr->left) curr = curr->left;
        return curr->val;
    }

    int findMax() const {
        if (!root_) throw runtime_error("Tree is empty");
        BSTNode* curr = root_;
        while (curr->right) curr = curr->right;
        return curr->val;
    }

    int height() const {
        return heightHelper(root_);
    }

    size_t size() const { return size_; }
    bool empty() const { return root_ == nullptr; }

private:
    BSTNode* root_;
    size_t size_;

    bool insertHelper(BSTNode* node, int val) {
        if (val == node->val) return false;
        if (val < node->val) {
            if (!node->left) {
                node->left = new BSTNode(val);
                size_++;
                return true;
            }
            return insertHelper(node->left, val);
        } else {
            if (!node->right) {
                node->right = new BSTNode(val);
                size_++;
                return true;
            }
            return insertHelper(node->right, val);
        }
    }

    void inOrderHelper(BSTNode* node, vector<int>& out) const {
        if (!node) return;
        inOrderHelper(node->left, out);
        out.push_back(node->val);
        inOrderHelper(node->right, out);
    }

    int heightHelper(BSTNode* node) const {
        if (!node) return 0;
        return 1 + max(heightHelper(node->left), heightHelper(node->right));
    }

    void destroy(BSTNode* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
};
