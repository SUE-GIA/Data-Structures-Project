#ifndef AVLTREE_H
#define AVLTREE_H

#include "AVLNode.h"

class AVLTree {
private:
    AVLNode* root;  // Pointer to the root node AVL tree

    AVLNode* insert(AVLNode* node, const Pair& pair);  //Insert a pair into the AVL tree
    void destroyTree(AVLNode* node);  // Destroy the AVL tree
    AVLNode* remove(AVLNode* node, const Pair& pair);  //Remove a pair from the AVL tree
    AVLNode* findMin(AVLNode* node);  //Find minimum pair in a subtree
    int getHeight(AVLNode* node);  //Get height of node
    int getBalance(AVLNode* node);  //Get the balance factor of a node
    AVLNode* rotateLeft(AVLNode* node);  //Perform a left rotation around a node
    AVLNode* rotateRight(AVLNode* node);  //Perform a right rotation around a node
    AVLNode* balanceNode(AVLNode* node);  //Balance a node (if necessary)
    int max(int a, int b);  //Helper function to get maximum of two integers

public:
    AVLTree();  // Constructor for AVLTree class
    ~AVLTree();  // Destructor for AVLTree class
    void insert(const Pair& pair);  //Insert a pair into AVL tree
    void remove(const Pair& pair);  //Remove a pair from AVL tree
    bool search(const Pair& pair);  //Search for a pair in AVL tree
    int getPairCount(const Pair& pair);  //Occurrence count of a pair in AVL tree
};

#endif //AVLTREE
