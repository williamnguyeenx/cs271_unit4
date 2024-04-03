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

            Node(T d, U k, Node *parent = nullptr, Node *l = nullptr, Node *r = nullptr) : data(d), key(k), p(parent), left(l), right(r) {}
        };

        Node* root; // pointer to root of BST

    public:
        BST     ( void ); // constructor
        ~BST    ( void );

        bool    empty( void );
        void    insert( const T& d, const U& k );
        T       get( const U& k ) const;
        void    remove( const U& k );

        T       max_data( void ) const;
        T       min_data( void ) const;
        U       max_key( void ) const;
        U       min_key( void ) const;

        U       successor( const U& k ) const;
        string  in_order( void ) const;
        void    trim( const U low, const U high );

        string  to_string( void ) const;
        void    deleteTree( Node* x);

        T getHelper(Node* x, const U& k) const;
        void transplant(Node* u, Node* v);

        U minKeyFromNode(Node* node) const;
        Node* trimRecursive(Node* node, U low, U high);
        
};

#endif

