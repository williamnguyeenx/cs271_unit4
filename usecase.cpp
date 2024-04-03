#include <fstream>
#include <sstream>
#include <string>
#include "BST.h" // Include your BST class header file here

using namespace std;

// Function to create a BST from a CSV file
template <class D, class K>
BST<D, K>* create_bst(const string& fname) 
{
    BST<D, K>* bst = new BST<D, K>();

    ifstream file(fname);

    if (!file.is_open()) {
        cerr << "Error opening file: " << fname << endl;
        exit(1);
    }
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string binary, hex;

        getline(ss, binary, ',');
        getline(ss, hex, ',');
        
        bst->insert(hex, binary);
    }
    file.close();
    return bst;
}

template <class D, class K>
string convert(BST<D, K>* bst, const string& bin) 
{
    // Pad the binary string if its length is not a multiple of 4
    int padding = bin.length() % 4;
    string padded_bin = string(4 - padding, '0') + bin;

    // Search for the binary string in the BST
    string hex = bst->get(padded_bin);
    return hex;
}

{
    while (bin.length() % 4 != 0)
}
