#include <iostream>
#include "usecase.cpp"  

using namespace std;

int main() {

    BST<string, string>* bst = create_bst<string, string>("binhex.txt");

    cout << "Enter binary: ";
    string binary;
    cin >> binary;

    string result = convert<string, string>(bst, binary);

    if (result == "Error") 
    {
        cout << "Can not convert binary to hexadecimal." << endl;
    } else
    {
        cout << "Hexadecimal representation: " << result << endl;
    }

       delete bst;

    return 0;     
}


