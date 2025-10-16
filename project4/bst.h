#pragma once
#include "item.h"
#include <vector>

class BST {
public:
    BST();
    ~BST();
    BST(const BST&) = delete;
    BST& operator=(const BST&) = delete;

    void   insert(const ItemHandle& v);
    bool   contains(const ItemHandle& v) const;
    bool   erase(const ItemHandle& v);      // leaf / 1 child / 2 children
    size_t size() const { return size_; }

    void   inorder(std::vector<ItemHandle>& out) const; // ascending by operator<
    bool   isValidBST() const;                          // strict check

private:
    struct Node {
        ItemHandle val;
        Node* left{nullptr};
        Node* right{nullptr};
        explicit Node(const ItemHandle& v) : val(v) {}
    };

    Node* root_{nullptr};
    size_t size_{0};
    void  clear(Node* n);
    Node* insertNode(Node* n, const ItemHandle& v, bool& added);
    bool  containsNode(Node* n, const ItemHandle& v) const;
    Node* eraseNode(Node* n, const ItemHandle& v, bool& erased);
    Node* detachMin(Node* n, Node*& minNode);
    void  inorderWalk(Node* n, std::vector<ItemHandle>& out) const;
    bool  isValid(Node* n, const ItemHandle* lo, const ItemHandle* hi) const;
};
