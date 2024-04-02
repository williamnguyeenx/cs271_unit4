#include "bst.h"
#include <iostream>
#include <sstream>
#include <string>


//=========================================================================
// base constructor
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
BST<T,U>::BST( void )
// Pre condition: 
// Post condition: 
{
    root = NULL;
}


//=========================================================================
// to_string
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
string BST<T,U>::to_string( void ) const
// Pre condition: 
// Post condition: 
{
    
}


//=========================================================================
// empty
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
bool BST<T,U>::empty( void )
// Pre condition: 
// Post condition: 
{
    return root == NULL;
}


//=========================================================================
// insert
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
void BST<T,U>::insert( const T d, const U k )
// Pre condition: 
// Post condition: 
{
    Node *z; // create new Node

    // fill new Node's attributes
    z->data = d; 
    z->key = k;
    z->left = NULL;
    z->right = NULL;

    // create pointers x and y
    Node* y = NULL;
    Node* x = root;

    // go down tree to location to insert
    while ( x != NULL ){
        y = x;
        if ( z->key < x->key ){
            x = x->left;
        }
        else{
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

/*
//=========================================================================
// get
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
T BST<T,U>::get( const U k )
// Pre condition: 
// Post condition: 
{

}


//=========================================================================
// remove
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
void BST<T,U>::remove( const U k )
// Pre condition: 
// Post condition: 
{

}


//=========================================================================
// max_data
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
T BST<T,U>::max_data( void )
// Pre condition: 
// Post condition: 
{

}


//=========================================================================
// min_data
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
T BST<T,U>::min_data( void )
// Pre condition: 
// Post condition: 
{

}


//=========================================================================
// max_key
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
U BST<T,U>::max_key( void )
// Pre condition: 
// Post condition: 
{

}


//=========================================================================
// min_key
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
U BST<T,U>::min_key( void )
// Pre condition: 
// Post condition: 
{

}


//=========================================================================
// successor
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
U BST<T,U>::successor( const U k )
// Pre condition: 
// Post condition: 
{

}


//=========================================================================
// in_order
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
string BST<T,U>::in_order( void )
// Pre condition: 
// Post condition: 
{

}


//=========================================================================
// trim
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>
void BST<T,U>::trim( const U low, const U high )
// Pre condition: 
// Post condition: 
{

}
*/


/*
//=========================================================================
// 
// Parameters:
// Returns:
// 
//=========================================================================
template <class T, class U>

// Pre condition: 
// Post condition: 
{

}
*/

