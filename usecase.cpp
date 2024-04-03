#include <fstream>
#include <sstream>
#include <string>
#include "bst.h" 

using namespace std;

//=========================================================================
// create_bst
// Parameters: const string& fname - name of the CSV file containing binary and hexadecimal pairs
// Returns: BST<D, K>* - pointer to the binary search tree created from the CSV file
// Description: Creates a binary search tree (BST) from a CSV file where each line represents
//              a pair of binary and hexadecimal values. The BST is initialized by inserting
//              each pair into the tree. Returns a pointer to the created BST.
//=========================================================================
template <class D, class K>
BST<D, K>* create_bst(const string& fname) 
{
    BST<D, K>* bst = new BST<D, K>(); // Create a new binary search tree

    ifstream file(fname); // Open the CSV file

    // Check if the file was opened successfully
    if (!file.is_open()) {
        cerr << "Error opening file: " << fname << endl; // Print error message
        exit(1); // Terminate program with error code 1
    }

    string line; // Variable to store each line read from the file

    // Read each line from the file
    while (getline(file, line)) {
        stringstream ss(line); // Create a stringstream to parse each line

        string binary, hex; // Variables to store binary and hexadecimal values

        // Extract binary and hexadecimal values from the stringstream
        getline(ss, binary, ',');
        getline(ss, hex, ',');
        
        // Insert the pair (binary, hex) into the binary search tree
        bst->insert(binary, hex);
    }

    file.close(); // Close the file after reading all lines
    return bst; // Return a pointer to the created binary search tree
}

//=========================================================================
// convert
// Parameters: BST<D, K>* bst, const string& bin
// Returns: string - hexadecimal representation of the input binary, or "Error" if conversion fails
// Description: Converts a binary string to its hexadecimal representation using the provided
//              BST containing pairs of binary and hexadecimal values.
//              The function iterates over the input binary string, extracting each 4-bit chunk
//              and looking up its corresponding hexadecimal value in the BST. If the conversion
//              fails for any chunk, the function returns "Error". Otherwise, it returns the
//              concatenated hexadecimal representation.
//=========================================================================
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

