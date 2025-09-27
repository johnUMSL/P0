#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <string>
#include <fstream>

// Tree building function
Node* buildTree(const std::vector<std::string>& words);

// Tree traversal functions
void printPreorder(Node* root, std::ofstream& outFile, int depth = 0);
void printInorder(Node* root, std::ofstream& outFile, int depth = 0);
void printPostorder(Node* root, std::ofstream& outFile, int depth = 0);

// Helper functions
Node* insert(Node* root, const std::string& word, int frequency);
void deleteTree(Node* root);

#endif