#ifndef BST_H
#define BST_H

#include "Pair.h"

class BST {
private:
  struct Node {
    Pair pair; //Pair stored in the node
    Node* left; //Pointer to the left child node
    Node* right;//Pointer to the right child node
    int occurrence; //Number of occurrences of the pair

    Node(const Pair& p) : pair(p), left(nullptr), right(nullptr), occurrence(1) {}
  };

  Node* root;    //Pointer to the root of BST
  int size;      //Current size of BST

public:
  BST(); //Constructor
  ~BST(); //Destructor
  void add(const Pair& newPair); //Add a pair to BST
  bool search(const Pair& targetPair) const; //Search for a pair in BST
  Pair getPair(int index) const; //Get the pair at specified index
  int getSize() const; //Get the current size of BST
  int getPairCount(const Pair& pair) const; //Get the occurrence count of a pair in BST

private:
  Node* insert(Node* node, const Pair& newPair); //Insert a pair into BST
  bool search(Node* node, const Pair& targetPair) const; //Search for a pair in BST
  void destroy(Node* node); //Recursively destroy BST
  int getPairCount(Node* node, const Pair& pair) const; //Get the occurrence count of a pair in BST
};

#endif //BST_H
