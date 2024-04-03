#include "bst.h"
#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

//=========================================================================
// default constructor
// Parameters: None
// Returns: N/A
// Initializes a binary search tree object by setting the root pointer to nullptr,
// indicating that the tree is initially empty.
//=========================================================================
template <class T, class U>
BST<T,U>::BST( void )
// Pre condition: None
// Post condition: The BST is initialized with root set to nullptr, indicating an empty tree.
{
    root = nullptr;
}

//=========================================================================
// Destructor
// Parameters: None
// Returns: N/A
// Properly deallocates all dynamically allocated memory used by the BST. This includes
// recursively deleting all nodes starting from the root to prevent memory leaks.
//=========================================================================
template <class T, class U>
BST<T,U>::~BST( void )
// Pre condition: BST exists
// Post condition: all data from BST is deallocated
{
    deleteTree(root);
}

//=========================================================================
// empty - Check if the BST is empty
// Parameters: None
// Returns: bool - True if the BST is empty (no nodes), false otherwise.
// This method checks if the binary search tree contains any nodes by verifying
// if the root pointer is nullptr. An empty tree indicates that no elements have
// been inserted into the BST.
//=========================================================================
template <class T, class U>
bool BST<T,U>::empty( void )
// Pre condition: BST exists
// Post condition: Returns if BST is empty
{
    return root == nullptr;
}


//=========================================================================
// insert
// Parameters: data value of type T and key value of type U
// Returns: None, but inserts into existing tree
// Inserts element with data d and key k into tree
//=========================================================================
template <class T, class U>
void BST<T,U>::insert( const T& d, const U& k )
// Pre condition: BST is a valid binary search tree
// Post condition: BST contains an element with data d and key k
{
    Node* z = new Node(d, k); // Create a new node
    if (root == nullptr) 
    {
        root = z; // the nodeNode become the root if tree is empty
        return;
    }

    // create pointers x and y
    Node* y = nullptr;
    Node* x = root;

    // go down tree to location to insert
    while ( x != nullptr )
    {
        y = x;
        if ( z->key < x->key )
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    z->p = y; // set z's parent

    // insert z
    if ( y == NULL )
        root = z;
    else if ( z->key < y->key )
        y->left = z;
    else 
        y->right = z;
}


//=========================================================================
// get
// Parameters: key value of type U
// Returns: data value of type T
// given a key, returns the data of an element in the tree
//=========================================================================
template <class T, class U>
T BST<T,U>::get( const U& k ) const
// Pre condition: BST is a valid binary search tree, and k is of type U
// Post condition: No changes, but returns the data of the element with the key k
{   
    return getHelper(root, k);
}


//=========================================================================
// getHelper
// Parameters: Node x, key k
// Returns: data value of type T
// Helper function to get data given a value
//=========================================================================
// Pre condition: BST is a valid binary search tree, and k is of type U
// Post condition: No changes, but returns the data of the element with the key k
template <class T, class U>
T BST<T,U>::getHelper(Node* x, const U& k) const 
{
    if (x == nullptr) // if tree is empty
    {
        return T();
    }
    if (x->key == k) // if x matches k
    {
        return x->data;
    }
    else if (x->key < k) // go right
    {
        return getHelper(x->right, k);
    } 
    else // go left
    {
        return getHelper(x->left, k);
    }
}


//=========================================================================
// transplant
// Parameters: Node u, Node v
// Returns: None, but alters tree
// Helper function to transplant two nodes in a tree
//=========================================================================
template <class T, class U>
void BST<T,U>::transplant(Node* u, Node* v)
// Pre condition: u and v are valid elements of the BST
// Post condition: u and v are now transplanted
{
    if (u->p == nullptr) { // if tree is empty
        root = v;
    } else if (u == u->p->left) {
        u->p->left = v;
    } else {
        u->p->right = v;
    }
    if (v != nullptr) {
        v->p = u->p;
    }
}


//=========================================================================
// remove
// Parameters: key value of type U
// Returns: none, but alters tree
// removes Node with key k from tree, maintaining BST properties
//=========================================================================
template <class T, class U>
void BST<T,U>::remove( const U& k )
// Pre condition: BST is a valid binary search tree, k is of type U
// Post condition: the node containing k is no longer in the BST, BST properties are maintained
{
    Node* z = root;
    Node* parent = nullptr;

    // Search for the node with key k
    while (z != nullptr && z->key != k)
    {
        parent = z;
        if (k < z->key)
        {
            z = z->left;
        }
        else
        {
            z = z->right;
        }
    }

    if (z == nullptr) // if tree is empty
    {
        return;
    }
    if (z->left == nullptr) 
    {
        transplant(z, z->right);
    } 
    else if (z->right == nullptr) 
    {
        transplant(z, z->left);
    } 
    else 
    {
        Node* y = z->right;
        while (y->left != nullptr)
        {
            y = y->left;
        }

        if (y->p != z) 
        {
            transplant(y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->p = y;
    }

    delete z; // Free the memory
}


//=========================================================================
// max_data
// Parameters: none
// Returns: data value of type T
// returns max data value in tree
//=========================================================================
template <class T, class U>
T BST<T,U>::max_data( void ) const
// Pre condition: BST is a valid binary search tree
// Post condition: no changes to tree, but returns max data value in tree 
{
    if (root == nullptr) // if tree is empty
    {
        return T();
    }
    Node* x = root;
    while (x->right != nullptr) // follow right children until at leaf
    {
       x = x->right;
    }
    return x->data;        
}


//=========================================================================
// min_data
// Parameters: none
// Returns: data value of type T
// returns min data value in tree
//=========================================================================
template <class T, class U>
T BST<T,U>::min_data( void ) const
// Pre condition: BST is a valid binary search tree
// Post condition: no changes to tree, but returns min data value in tree 
{
    if (root == nullptr) // if tree is empty
    {
        return T();
    }
    Node* x = root;
    while (x->left != nullptr) // follow left children until at leaf
    {
        x = x->left;
    }
    return x->data;
}


//=========================================================================
// max_key
// Parameters: none
// Returns: key value of type U
// returns max key value in tree
//=========================================================================
template <class T, class U>
U BST<T,U>::max_key( void ) const
// Pre condition: BST is a valid binary search tree
// Post condition: no changes to tree, but returns max key value in tree 
{
    if (root == nullptr) // if tree is empty
    {
        return U();
    }
    Node* x = root;
    while (x->right != nullptr) // follow right children until at leaf
    {
        x = x->right;
    }
    return x->key;
}


//=========================================================================
// min_key
// Parameters: none
// Returns: key value of type U
// returns min key value in tree
//=========================================================================
template <class T, class U>
U BST<T,U>::min_key( void ) const
// Pre condition: BST is a valid binary search tree
// Post condition: no changes to tree, but returns min key value in tree 
{
    if (root == nullptr) // if tree is empty
    {
        return U();
    }
    Node* x = root;
    while (x->left != nullptr) // folllow left children until at leaf
    {
        x = x->left;
    }
    return x->key;
}


//=========================================================================
// successor
// Parameters: key value of type U
// Returns: key value of type U
// returns the key of the successor of the element with key k
//=========================================================================
template <class T, class U>
U BST<T,U>::successor( const U& k ) const
// Pre condition: bst is a valid binary search tree, k is of type U
// Post condition: no changes to tree, but returns the key of the successor of the element with key k
{
    Node* x = root;
    Node* parent = nullptr;

    // Search for the node with key k
    while (x != nullptr && x->key != k)
    {
        parent = x;
        if (k < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    if (x == nullptr) // if tree is empty
    {
        return U();
    }

    if (x->right != nullptr) // if right child is null
    {
        return getHelperSpecificNode(x->right);
    }

    Node* y = parent;
    while (y != nullptr && x == y->right) 
    {
        x = y;
        y = y->p;
    }

    if (y == nullptr) 
    {
        return U();
    }

    return y->key;
}


//=========================================================================
// getHelperSpecificNode
// Parameters: Node
// Returns: key value of type U
// helper function for successor
//=========================================================================
template <class T, class U>
U BST<T,U>::getHelperSpecificNode(Node* node) const {
// Pre condition: bst is a valid binary search tree, node is a valid node in the tree
// Post condition: returns key of the successor of node
    if (node == nullptr) {
        return U(); // Or throw an exception if that makes more sense for your application
    }

    while (node->left != nullptr) {
        node = node->left;
    }

    return node->key;
}


//=========================================================================
// in_order
// Parameters: none
// Returns: string of values of BST in order
// performs an in order tree walk, and returns a string of the elements of the tree, sorted ascending
//=========================================================================
template <class T, class U>
string BST<T,U>::in_order( void ) const
// Pre condition: tree is a valid binary search tree
// Post condition: no changes to tree, but prints the elements of the bst in ascending order
{
    stringstream order;
    U x = getHelperSpecificNode(root);

    while (successor(x) != U())
    {
        order << x << " ";
        x = successor(x);
    }
    order << x;

    return order.str();
        
}


//=========================================================================
// trim
// Parameters: U low, U high (range of data values to trim tree)
// Returns: none, but removes all elements from tree with data values not in range
// removes all elements from tree with data values not in range
//=========================================================================
template <class T, class U>
void BST<T,U>::trim( const U low, const U high )
// Pre condition: bst is a valid binary search tree, low and high are both of type U, and low is less than high
// Post condition: bst is trimmed so all elements are within the range (low, high)
{
    root = trimHelper(root, low, high);
}


//=========================================================================
// deleteTree 
// Parameters: Node* node - pointer to the current node in the BST
// Returns: N/A
// Recursively deletes all nodes in the binary search tree, freeing up memory. It traverses
// the tree in post-order to ensure that child nodes are deleted before their parent.
//=========================================================================
template <class T, class U>
void BST<T,U>::deleteTree( Node* x)
// Pre condition: tree is a valid binary search tree, x is the root of this tree
// Post condition: tree is deleted and fully deallocated
{
    if (x != nullptr)
    {
        deleteTree(x->right);
        deleteTree(x->left);
        delete x;
    }
}


// =========================================================================
// to_string
// Parameters: none
// Returns: string
// returns a string containing values of BST from top to bottom, left to right
// =========================================================================
template <class T, class U>
string BST<T,U>::to_string( void ) const
// Pre condition: tree is a valid binary search tree
// Post condition: no changes to tree, but returns a string containing the values of the BST from top to bottom, left to right
{
    stringstream result;
    queue<Node*> temp;
    if (root == nullptr)
    {
        return result.str();

    }
    temp.push(root); // EnQueue the root node

    while (!temp.empty())
    {
        Node* x = temp.front(); // Get front node, node x is the current node
        temp.pop(); // DeQueue the front node

        if (x->left != nullptr) // EnQueue the left child
        {
            temp.push(x->left);
        }
        if (x->right != nullptr) // EnQueue the right child
        {
            temp.push(x->right);
        }

        result << x->key;

        if(!temp.empty())
        {
            result << " ";
        }       
    }

    return result.str();
}


//=========================================================================
// trimHelper
// Parameters: Node, U low, U high (range of data values to trim tree)
// Returns: typename
// helper function for trim
//=========================================================================
template <class T, class U>
typename BST<T,U>::Node* BST<T,U>::trimHelper(Node* node, U low, U high) {
// Pre condition: tree is a valid bst, node is the root of the BST, low is less than high
// Post condition: tree is trimmed 
    // If the current node is null, return null.
    if (node == nullptr) {
        return nullptr;
    }

    // Recursively trim the left and right subtrees.
    node->left = trimHelper(node->left, low, high);
    node->right = trimHelper(node->right, low, high);

    // If the current node's key is less than the low end of the range,
    // discard the current node and its left subtree,
    // returning the right subtree to be reconnected.
    if (node->key < low) {
        Node* rightSubtree = node->right;
        delete node; // Remove the current node.
        return rightSubtree;
    }
    // If the current node's key is greater than the high end of the range,
    // discard the current node and its right subtree,
    // returning the left subtree to be reconnected.
    else if (node->key > high) {
        Node* leftSubtree = node->left;
        delete node; // Remove the current node.
        return leftSubtree;
    }

    return node;
}

