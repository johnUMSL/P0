#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

struct Node {
    int frequency;
    std::string data;
    std::vector<std::string> allStrings;  // For multiple strings with same frequency
    Node* left;
    Node* right;
    
    // Constructor
    Node(const std::string& str, int freq) 
        : frequency(freq), data(str), left(nullptr), right(nullptr) {
        allStrings.push_back(str);
    }
};

#endif