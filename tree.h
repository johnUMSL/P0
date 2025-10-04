#ifndef TREE_H
#define TREE_H

#include <string>
#include <ostream>
#include "node.h"

// Insert a string into BST keyed by frequency
Node* buildTree(Node* root, const std::string &word, int freq);

void printPreorder(Node* root, std::ostream& out, int depth = 0);
void printInorder(Node* root, std::ostream& out, int depth = 0);
void printPostorder(Node* root, std::ostream& out, int depth = 0);

#endif