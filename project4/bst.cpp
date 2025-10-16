#include "bst.h"

BST::BST() : root_(nullptr), size_(0) {}
BST::~BST() { clear(root_); }

void BST::clear(Node* n) {
    if (!n) return;
    clear(n->left);
    clear(n->right);
    delete n;
}

BST::Node* BST::insertNode(Node* n, const ItemHandle& v, bool& added) {
    if (!n) {
        added = true;
        return new Node(v);
    }
    if (v < n->val) {
        n->left = insertNode(n->left, v, added);
    } else if (n->val < v) {
        n->right = insertNode(n->right, v, added);
    }
    return n;
}

void BST::insert(const ItemHandle& v) {
    bool added = false;
    root_ = insertNode(root_, v, added);
    if (added) ++size_;
}

bool BST::containsNode(Node* n, const ItemHandle& v) const {
    if (!n) {
        return false;
    }
    if (v < n->val) {
        return containsNode(n->left, v);
    } else if (n->val < v) {
        return containsNode(n->right, v);
    } else {
        return true;
    }
}
bool BST::contains(const ItemHandle& v) const { return containsNode(root_, v); }

void BST::inorderWalk(Node* n, std::vector<ItemHandle>& out) const {
    if (!n) {
        return;}
    inorderWalk(n->left, out);
    out.push_back(n->val);
    inorderWalk(n->right, out);
}
void BST::inorder(std::vector<ItemHandle>& out) const { out.clear(); inorderWalk(root_, out); }

bool BST::isValid(Node* n, const ItemHandle* lo, const ItemHandle* hi) const {
    if (!n){ return true;}
    if (lo && !( *lo < n->val )) {return false;}
    if (hi && !( n->val < *hi )) {return false;}
    return isValid(n->left, lo, &n->val) && isValid(n->right, &n->val, hi);
}
bool BST::isValidBST() const { return isValid(root_, nullptr, nullptr); }

BST::Node* BST::detachMin(Node* n, Node*& minNode) {
    if (!n->left) {
        minNode = n;
        return n->right;
    }
    n->left = detachMin(n->left, minNode);
    return n;
}

BST::Node* BST::eraseNode(Node* n, const ItemHandle& v, bool& erased) {
    if (!n) {
        return nullptr;
    }

    if (v < n->val) {
        n->left = eraseNode(n->left, v, erased);
    } else if (n->val < v) {
        n->right = eraseNode(n->right, v, erased);
    } else {
        erased = true;
        Node* temp;

        if (!n->left) {
            temp = n->right;
            delete n;
            return temp;
        } else if (!n->right) {
            temp = n->left;
            delete n;
            return temp;
        } else {
            Node* b = nullptr;
            n->right = detachMin(n->right, b);
            b->left = n->left;
            b->right = n->right;
            delete n;
            return b;
        }
    }
    return n;
}

bool BST::erase(const ItemHandle& v) {
    bool erased = false;
    root_ = eraseNode(root_, v, erased);
    if (erased) --size_;
    return erased;
}
