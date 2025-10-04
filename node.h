#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

struct Node {
    int freq;                       // frequency (key)
    std::vector<std::string> items; // all strings with this frequency
    Node *left;
    Node *right;

    Node(int f, const std::string &word)
        : freq(f), left(nullptr), right(nullptr) {
        items.push_back(word);
    }
};

#endif