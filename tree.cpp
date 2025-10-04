#include "tree.h"
#include <iostream>
#include <algorithm>

using namespace std;

Node* buildTree(Node* root, const string &word, int freq) {
    if (!root)
        return new Node(freq, word);

    if (freq < root->freq)
        root->left = buildTree(root->left, word, freq);
    else if (freq > root->freq)
        root->right = buildTree(root->right, word, freq);
    else
        root->items.push_back(word);  // same frequency -> same node

    return root;
}

// Printing helpers
static void printNode(Node* n, ostream& out, int depth) {
    for (int i = 0; i < depth * 2; ++i)
        out.put(' ');
    out << n->freq << ": ";
    for (size_t i = 0; i < n->items.size(); ++i) {
        out << n->items[i];
        if (i + 1 < n->items.size()) out << ' ';
    }
    out << '\n';
}

void printPreorder(Node* root, ostream& out, int depth) {
    if (!root) return;
    printNode(root, out, depth);
    printPreorder(root->left, out, depth + 1);
    printPreorder(root->right, out, depth + 1);
}

void printInorder(Node* root, ostream& out, int depth) {
    if (!root) return;
    printInorder(root->left, out, depth + 1);
    printNode(root, out, depth);
    printInorder(root->right, out, depth + 1);
}

void printPostorder(Node* root, ostream& out, int depth) {
    if (!root) return;
    printPostorder(root->left, out, depth + 1);
    printPostorder(root->right, out, depth + 1);
    printNode(root, out, depth);
}