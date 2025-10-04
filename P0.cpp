#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "tree.h"
#include "node.h"

using namespace std;

static void exitError(const string &s) {
    cout << s << endl;
    exit(1);
}

// find or add string in vector and increment count
static void addOrIncrement(vector<pair<string,int>> &data, const string &word) {
    for (auto &p : data) {
        if (p.first == word) {
            p.second++;
            return;
        }
    }
    data.push_back({word, 1});
}

int invoke(int argc, char *argv[]) {
    if (argc > 2)
        exitError("Too many arguments");

    string base = (argc == 2) ? string(argv[1]) : string("out");

    istream *in = &cin;
    ifstream infile;
    if (argc == 2) {
        string filename = base + ".fs25s1";
        infile.open(filename);
        if (!infile)
            exitError("Cannot open file " + filename);
        cout << "Reading from file: " << filename << endl;
        in = &infile;
    } else {
        cout << "Reading from keyboard (Ctrl+D to end):" << endl;
    }

    // Step 1: Read input and record each string + frequency in vector
    vector<pair<string,int>> words; // keeps insertion order
    string token;
    while (*in >> token) {
        addOrIncrement(words, token);
    }

    // Step 2: Build BST using frequency rule
    Node *root = nullptr;
    for (auto &p : words) {
        root = buildTree(root, p.first, p.second);
    }

    // Step 3: Write traversals
    {
        ofstream f(base + ".preorder");
        if (!f) exitError("Cannot open " + base + ".preorder");
        printPreorder(root, f);
    }
    {
        ofstream f(base + ".inorder");
        if (!f) exitError("Cannot open " + base + ".inorder");
        printInorder(root, f);
    }
    {
        ofstream f(base + ".postorder");
        if (!f) exitError("Cannot open " + base + ".postorder");
        printPostorder(root, f);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    return invoke(argc, argv);
}