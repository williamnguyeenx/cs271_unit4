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
// Parameters: Node* u - pointer to the node to be replaced, Node* v - pointer
//             to the node that replaces u
// Returns: None, but alters tree structure
// Description: Helper function to transplant two nodes in a binary search tree.
//              Replaces the subtree rooted at node u with the subtree rooted at node v.
//=========================================================================
template <class T, class U>
void BST<T,U>::transplant(Node* u, Node* v)
// Precondition: u and v are valid nodes in the binary search tree
// Postcondition: The subtree rooted at node u is replaced by the subtree rooted at node v
{
    if (u->p == nullptr) { // If u is the root of the tree
        root = v; // Update the root pointer to point to v
    } else if (u == u->p->left) { // If u is a left child of its parent
        u->p->left = v; // Update the left child pointer of u's parent to point to v
    } else { // If u is a right child of its parent
        u->p->right = v; // Update the right child pointer of u's parent to point to v
    }
    if (v != nullptr) { // If v is not null
        v->p = u->p; // Update the parent pointer of v to point to u's parent
    }
}


//=========================================================================
// remove
// Parameters: const U& k - key value of type U to be removed from the tree
// Returns: None, but alters the tree structure
// Description: Removes the node with key k from the binary search tree while maintaining
//              the properties of a binary search tree.
//=========================================================================
template <class T, class U>
void BST<T,U>::remove( const U& k )
// Precondition: BST is a valid binary search tree, k is of type U
// Postcondition: The node containing key k is removed from the BST, and BST properties are maintained
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

    if (z == nullptr) // If the node with key k is not found
    {
        return; // No action needed, key not found
    }

    // Case 1: If the node to be removed has no left child
    if (z->left == nullptr) 
    {
        transplant(z, z->right); // Replace z with its right child
    } 
    // Case 2: If the node to be removed has no right child
    else if (z->right == nullptr) 
    {
        transplant(z, z->left); // Replace z with its left child
    } 
    // Case 3: If the node to be removed has both left and right children
    else 
    {
        // Find the successor of z (smallest node in the right subtree)
        Node* y = z->right;
        while (y->left != nullptr)
        {
            y = y->left;
        }

        // If the successor is not the right child of z
        if (y->p != z) 
        {
            // Replace y with its right child
            transplant(y, y->right);
            // Update the right child of y to be the right child of z
            y->right = z->right;
            y->right->p = y;
        }
        // Replace z with its successor y
        transplant(z, y);
        // Update the left child of y to be the left child of z
        y->left = z->left;
        y->left->p = y;
    }

    delete z; // Free the memory occupied by the removed node
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
// Parameters: const U& k - key value of type U
// Returns: U - key value of type U
// Description: Returns the key value of the successor of the element with 
//              the key k in the binary search tree.
//=========================================================================
template <class T, class U>
U BST<T,U>::successor( const U& k ) const
// Pre condition: bst is a valid binary search tree, k is of type U
// Post condition: no changes to tree, but returns the key of the successor of the element with key k
{
    // Initialize pointers for traversal
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
        return U(); // Return a default value of type U
    }

    if (x->right != nullptr) // if right child is null
    {
        return getHelperSpecificNode(x->right);
    }

    // If the right child is null, traverse the tree to find the successor
    Node* y = parent;
    while (y != nullptr && x == y->right) 
    {
        x = y;
        y = y->p;
    }

    // If y is null, indicating x is the largest element in the tree
    if (y == nullptr) 
    {
        return U();
    }

    return y->key;
}


//=========================================================================
// getHelperSpecificNode
// Parameters: Node* node - a pointer to the node
// Returns: U - key value of type U
// Description: This is a helper function for the successor method. It traverses
//              the left subtree of the given node to find the node with the smallest
//              key value, which represents the successor of the given node.
//=========================================================================
template <class T, class U>
U BST<T,U>::getHelperSpecificNode(Node* node) const {
// Pre condition: bst is a valid binary search tree, node is a valid node in the tree
// Post condition: returns key of the successor of node
    if (node == nullptr) {
        return U(); // Or throw an exception if that makes more sense for your application
    }

    while (node->left != nullptr) { // Traverse the left subtree to find the node with the smallest key value
        node = node->left;
    }

    return node->key;
}


//=========================================================================
// in_order
// Parameters: none
// Returns: string - string of values of BST in order
// Description: Performs an in-order tree walk and returns a string of the elements
//              of the tree sorted in ascending order.
//=========================================================================
template <class T, class U>
string BST<T,U>::in_order( void ) const
// Pre condition: tree is a valid binary search tree
// Post condition: no changes to tree, but prints the elements of the bst in ascending order
{
    stringstream order; // Initialize a stringstream to store the elements of the tree
    U x = getHelperSpecificNode(root); // Find the smallest key value in the binary search tree

    while (successor(x) != U()) // Traverse the binary search tree using successor method
    {
        order << x << " "; // Append the current key value to the stringstream
        x = successor(x); // Move to the next key value
    }
    order << x; // Append the last key value to the stringstream

    return order.str(); // Return the stringstream content as a string
        
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

