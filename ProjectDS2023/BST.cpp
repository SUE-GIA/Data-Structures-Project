#include "BST.h"

// Constructor
BST::BST() : root(nullptr), size(0) {}

// Destructor
BST::~BST() {
  destroy(root);
}

//Add a new Pair to BST
void BST::add(const Pair& newPair) {
  root = insert(root, newPair);
}

//Search for a Pair in bST
bool BST::search(const Pair& targetPair) const {
  return search(root, targetPair);
}

//Get the Pair at the specified index
Pair BST::getPair(int index) const {
  Node* current = root;
  int count = 0;

  while (current != nullptr) {
    if (current->left == nullptr) {
      if (count == index) {
        return current->pair;
      }
      count++;
      current = current->right;
    } else {
      Node* predecessor = current->left;

      while (predecessor->right != nullptr && predecessor->right != current) {
        predecessor = predecessor->right;
      }

      if (predecessor->right == nullptr) {
        predecessor->right = current;
        current = current->left;
      } else {
        predecessor->right = nullptr;
        if (count == index) {
          return current->pair;
        }
        count++;
        current = current->right;
      }
    }
  }

  return Pair();
}

//Get the size of BST
int BST::getSize() const {
  return size;
}

//Get the occurrence count of a Pair
int BST::getPairCount(const Pair& pair) const {
  return getPairCount(root, pair);
}

//Insert a Pair into BST
BST::Node* BST::insert(Node* node, const Pair& newPair) {
  if (node == nullptr) {
    size++;
    return new Node(newPair);
  }

  if (newPair < node->pair) {
    node->left = insert(node->left, newPair);
  } else if (node->pair < newPair) {
    node->right = insert(node->right, newPair);
  } else {
    //node->pair = newPair; //Update the pair
    node->occurrence++; //Increment the count of occurrences
  }

  return node;
}

//Search for a Pair
bool BST::search(Node* node, const Pair& targetPair) const {
  if (node == nullptr) {
    return false;
  }

  if (targetPair < node->pair) {
    return search(node->left, targetPair);
  } else if (node->pair < targetPair) {
    return search(node->right, targetPair);
  } else {
    return true;
  }
}

//Destroy the BST, free memory
void BST::destroy(Node* node) {
  if (node != nullptr) {
    destroy(node->left);
    destroy(node->right);
    delete node;
  }
}

//Get the occurrence count of Pair
int BST::getPairCount(Node* node, const Pair& pair) const {
  if (node == nullptr) {
    return 0;
  }

  if (pair < node->pair) {
    return getPairCount(node->left, pair);
  } else if (node->pair < pair) {
    return getPairCount(node->right, pair);
  } else {
    return node->occurrence;
  }
}
