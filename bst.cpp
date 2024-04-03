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
// Pre condition: 
// Post condition: 
{
    return root == nullptr;
}


//=========================================================================
// insert
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
void BST<T,U>::insert( const T& d, const U& k )
// Pre condition: 
// Post condition: 
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
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
T BST<T,U>::get( const U& k ) const
// Pre condition: 
// Post condition: 
{   
    return getHelper(root, k);
}

//=========================================================================
// get
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
T BST<T,U>::getHelper(Node* x, const U& k) const 
{
    if (x == nullptr)
    {
        return T();
    }
    if (x->key == k) 
    {
        return x->data;
    }
    else if (x->key < k) 
    {
        return getHelper(x->right, k);
    } 
    else 
    {
        return getHelper(x->left, k);
    }
}

template <class T, class U>
void BST<T,U>::transplant(Node* u, Node* v)
{
    if (u->p == nullptr) {
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
// Parameters:
// Returns:
// 
//=========================================================================

template <class T, class U>
void BST<T,U>::remove( const U& k )
// Pre condition: 
// Post condition: 
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

    if (z == nullptr)
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
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
T BST<T,U>::max_data( void ) const
// Pre condition: 
// Post condition: 
{
    if (root == nullptr) 
    {
        return T();
    }
    Node* x = root;
    while (x->right != nullptr) 
    {
       x = x->right;
    }
    return x->data;        

}


//=========================================================================
// min_data
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
T BST<T,U>::min_data( void ) const
// Pre condition: 
// Post condition: 
{
    if (root == nullptr) 
    {

        return T();
    }
    Node* x = root;
    while (x->left != nullptr) 
    {
        x = x->left;
    }
    return x->data;
}


//=========================================================================
// max_key
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
U BST<T,U>::max_key( void ) const
// Pre condition: 
// Post condition: 
{
    if (root == nullptr) 
    {
        return U();
    }
    Node* x = root;
    while (x->right != nullptr) 
    {
        x = x->right;
    }
    return x->key;
}


//=========================================================================
// min_key
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
U BST<T,U>::min_key( void ) const
// Pre condition: 
// Post condition: 
{
    if (root == nullptr) 
    {
        return U();
    }
    Node* x = root;
    while (x->left != nullptr) 
    {
        x = x->left;
    }
    return x->key;
}

//=========================================================================
// successor
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
U BST<T,U>::successor( const U& k ) const
// Pre condition: 
// Post condition: 
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

    if (x == nullptr) 
    {
        return U();
    }

    if (x->right != nullptr) 
    {
        return min_key(x->right);
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
// in_order
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
string BST<T,U>::in_order( void ) const
// Pre condition: 
// Post condition: 
{
    string order;
    T x = min_key();

    while (successor(x) != NULL)
    {
        if (successor(x) == NULL)
        {
            order = order + x;
        }
        order = order + x + " ";
        x = successor(x);
    }

    return order;
        
}


//=========================================================================
// trim
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
void BST<T,U>::trim( const U low, const U high ) const
// Pre condition: 
// Post condition: 
{

    BST<T,U> trimmed; 

    T x = min_key();

    while (x < low)
    {
        x = successor(x);
    }

    while (successor(x) != NULL && x >= low && x <= high)
    {
        trimmed.insert(x);
        x = successor(x);
    }

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
// Parameters:
// Returns:

// =========================================================================

template <class T, class U>
string BST<T,U>::to_string( void ) const
// Pre condition: 
// Post condition: 
{
    stringstream result;
    queue<Node*> temp;
    if (root == nullptr)
    {
        return "";

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
