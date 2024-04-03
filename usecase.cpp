#include <fstream>
#include <sstream>
#include <string>
#include "bst.h" 

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
        
        bst->insert(binary, hex);
    }
    file.close();
    return bst;
}

template <class D, class K>
string convert(BST<D, K>* bst, const string& bin) 
{
    // Make bin length is a multiple of 4 by adding 0 if it is not a multiple of 4
    string newBin = bin;
    while (newBin.length() % 4 != 0) {
        newBin = "0" + newBin;
    }
    // Initialize an empty string for storing
    string hex = "";

    // Iterate over the newbin string in every 4 bits
    for (int i = 0; i < newBin.size(); i += 4) 
    {
        // Extract the current 4-bit binary chunk
        string binary = newBin.substr(i, 4);
        string hexNum = "";

        // Look up the hexNum that match the binary chunk in BST
        hexNum = bst->get(binary);

        // If the hexNnum is not found in the BST, set hex to "Error" and break
        if (hexNum.empty()) 
        {
            hex = "Error";
            break;
        }

        // Append the hexNum to the hex string
        hex += hexNum;
    }

    // Return the hexadecimal representation
    return hex;
}

