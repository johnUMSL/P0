#include "tree.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

// Insert a node into the BST based on frequency
Node* insert(Node* root, const string& word, int frequency) {
    if (root == nullptr) {
        return new Node(word, frequency);
    }
    
    if (frequency < root->frequency) {
        root->left = insert(root->left, word, frequency);
    } else if (frequency > root->frequency) {
        root->right = insert(root->right, word, frequency);
    } else {
        // Same frequency - add to existing node
        root->allStrings.push_back(word);
    }
    
    return root;
}

// Build tree from vector of words
Node* buildTree(const vector<string>& words) {
    // Count frequencies
    map<string, int> frequencies;
    for (const string& word : words) {
        frequencies[word]++;
    }
    
    Node* root = nullptr;
    
    // Insert each unique word with its frequency
    for (const auto& pair : frequencies) {
        root = insert(root, pair.first, pair.second);
    }
    
    return root;
}

// Helper function to calculate actual depth of a node
void printPreorderHelper(Node* root, ofstream& outFile, int depth) {
    if (root == nullptr) return;
    
    // Print current node
    for (int i = 0; i < depth * 2; i++) {
        outFile << " ";
    }
    outFile << root->frequency << ": ";
    for (size_t i = 0; i < root->allStrings.size(); i++) {
        if (i > 0) outFile << " ";
        outFile << root->allStrings[i];
    }
    outFile << endl;
    
    // Traverse left then right
    printPreorderHelper(root->left, outFile, depth + 1);
    printPreorderHelper(root->right, outFile, depth + 1);
}

void printInorderHelper(Node* root, ofstream& outFile, int depth) {
    if (root == nullptr) return;
    
    // Traverse left
    printInorderHelper(root->left, outFile, depth + 1);
    
    // Print current node
    for (int i = 0; i < depth * 2; i++) {
        outFile << " ";
    }
    outFile << root->frequency << ": ";
    for (size_t i = 0; i < root->allStrings.size(); i++) {
        if (i > 0) outFile << " ";
        outFile << root->allStrings[i];
    }
    outFile << endl;
    
    // Traverse right
    printInorderHelper(root->right, outFile, depth + 1);
}

void printPostorderHelper(Node* root, ofstream& outFile, int depth) {
    if (root == nullptr) return;
    
    // Traverse left then right
    printPostorderHelper(root->left, outFile, depth + 1);
    printPostorderHelper(root->right, outFile, depth + 1);
    
    // Print current node
    for (int i = 0; i < depth * 2; i++) {
        outFile << " ";
    }
    outFile << root->frequency << ": ";
    for (size_t i = 0; i < root->allStrings.size(); i++) {
        if (i > 0) outFile << " ";
        outFile << root->allStrings[i];
    }
    outFile << endl;
}

// Preorder traversal: root, left, right
void printPreorder(Node* root, ofstream& outFile, int depth) {
    printPreorderHelper(root, outFile, depth);
}

// Inorder traversal: left, root, right
void printInorder(Node* root, ofstream& outFile, int depth) {
    printInorderHelper(root, outFile, depth);
}

// Postorder traversal: left, right, root
void printPostorder(Node* root, ofstream& outFile, int depth) {
    printPostorderHelper(root, outFile, depth);
}

// Clean up memory
void deleteTree(Node* root) {
    if (root == nullptr) return;
    
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}