#include <iostream>
#include <string>
#include <chrono>

using namespace std;

// Header guards
#ifndef BST_H
#define BST_H

template <class T, class U> // T = data, U = key
class BST
{
    private:
        struct Node // struct for Node for tree
        {
            T data;
            U key;
            Node *p;
            Node *left;
            Node *right;
        };

        Node* root; // pointer to root of BST

    public:
        BST( void ); // constructor

        bool    empty( void );
        void    insert( const T d, const U k );
        T       get( const U k );
        void    remove( const U k );

        T       max_data( void );
        T       min_data( void );
        U       max_key( void );
        U       min_key( void );

        U       successor( const U k );
        string  in_order( void );
        void    trim( const U low, const U high );

        string  to_string( void ) const;
};

#endif

