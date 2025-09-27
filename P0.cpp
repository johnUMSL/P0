#include "tree.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function to validate that a string contains only letters and digits
bool isValidString(const string& str) {
    if (str.empty()) return false;
    
    for (char c : str) {
        if (!isalnum(c)) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    // Check command line arguments
    if (argc > 2) {
        cerr << "Error: Too many arguments. Usage: P0 [filename]" << endl;
        return 1;
    }
    
    vector<string> words;
    string basename = "out";  // Default basename for output files
    
    // Determine input source
    if (argc == 1) {
        // Read from stdin
        string word;
        while (cin >> word) {
            if (isValidString(word)) {
                words.push_back(word);
            } else {
                cerr << "Warning: Skipping invalid datum '" << word << "' (contains non-alphanumeric characters)" << endl;
            }
        }
    } else {
        // Read from file
        basename = argv[1];
        string filename = basename + ".fs25s1";
        
        ifstream inFile(filename);
        if (!inFile.is_open()) {
            cerr << "Error: Cannot open file " << filename << endl;
            return 1;
        }
        
        string word;
        while (inFile >> word) {
            if (isValidString(word)) {
                words.push_back(word);
            } else {
                cerr << "Warning: Skipping invalid datum '" << word << "' (contains non-alphanumeric characters)" << endl;
            }
        }
        inFile.close();
    }
    
    // Check if we have any words
    if (words.empty()) {
        cerr << "Error: No input data" << endl;
        return 1;
    }
    
    // Build the tree
    Node* root = buildTree(words);
    
    // Generate output files
    string preorderFile = basename + ".preorder";
    string inorderFile = basename + ".inorder";
    string postorderFile = basename + ".postorder";
    
    // Write preorder traversal
    ofstream preOut(preorderFile);
    if (!preOut.is_open()) {
        cerr << "Error: Cannot create " << preorderFile << endl;
        deleteTree(root);
        return 1;
    }
    printPreorder(root, preOut);
    preOut.close();
    
    // Write inorder traversal
    ofstream inOut(inorderFile);
    if (!inOut.is_open()) {
        cerr << "Error: Cannot create " << inorderFile << endl;
        deleteTree(root);
        return 1;
    }
    printInorder(root, inOut);
    inOut.close();
    
    // Write postorder traversal
    ofstream postOut(postorderFile);
    if (!postOut.is_open()) {
        cerr << "Error: Cannot create " << postorderFile << endl;
        deleteTree(root);
        return 1;
    }
    printPostorder(root, postOut);
    postOut.close();
    
    // Clean up
    deleteTree(root);
    
    cout << "Tree traversals written to:" << endl;
    cout << "  " << preorderFile << endl;
    cout << "  " << inorderFile << endl;
    cout << "  " << postorderFile << endl;
    
    return 0;
}