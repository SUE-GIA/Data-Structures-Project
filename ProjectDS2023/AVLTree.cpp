#include "AVLTree.h"

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {
    destroyTree(root);
}

//Insert a pair into AVL tree
void AVLTree::insert(const Pair& pair) {
    root = insert(root, pair);  //Call private insert function
}

//Destroy the AVL tree Recursivelyy
void AVLTree::destroyTree(AVLNode* node) {
    if (node == nullptr) {
        return;
    }

    destroyTree(node->left);
    destroyTree(node->right);

    delete node;  //Delete current node
}

//Private insert function to recursively insert a pair into the AVL tree
AVLNode* AVLTree::insert(AVLNode* node, const Pair& pair) {
    if (node == nullptr) {
        return new AVLNode(pair);  //Create new node pair
    }

    if (pair == node->pair) {
        //Update occurrence count if it exists in the tree
        node->pair.incrementOccurrence();
        return node;
    }

    if (pair < node->pair) {
        node->left = insert(node->left, pair);  //Recursively insert into the left subtree
    } else {
        node->right = insert(node->right, pair);  //Recursively insert into the right subtree
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;  //Update the height of the current node

    return balanceNode(node);  //Balance the node if necessary
}

//Remove a pair from AVL tree
void AVLTree::remove(const Pair& pair) {
    root = remove(root, pair);  //Call the private remove function
}

//Private remove function to recursively remove a pair from the AVL tree
AVLNode* AVLTree::remove(AVLNode* node, const Pair& pair) {
    if (node == nullptr) {
        return nullptr;
    }

    if (pair < node->pair) {
        node->left = remove(node->left, pair);  //Recursively remove from the left subtree
    } else if (pair > node->pair) {
        node->right = remove(node->right, pair);  //Recursively remove from the right subtree
    } else {
        if (node->pair.getOccurrence() > 1) {
            //Decrease occurrence count if the pair has multiple occurrences
            node->pair.incrementOccurrence();
            return node;
        }

        if (node->left == nullptr || node->right == nullptr) {
            AVLNode* temp = node->left ? node->left : node->right;
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            delete temp;
        } else {
            //Replace the pair with the min from the right subtree
            AVLNode* minNode = findMin(node->right);
            node->pair = minNode->pair;
            node->right = remove(node->right, minNode->pair);
        }
    }

    if (node == nullptr) {
        return node;
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;  //Update height of current node

    return balanceNode(node);  //Balance node (if necessary)
}

//Find the minimum pair in a subtree
AVLNode* AVLTree::findMin(AVLNode* node) {
    if (node == nullptr) {
        return nullptr;
    }

    while (node->left != nullptr) {
        node = node->left;
    }

    return node;
}

//Search for a pair in the AVL tree
bool AVLTree::search(const Pair& pair) {
    AVLNode* current = root;

    while (current != nullptr) {
        if (pair == current->pair) {
            return true;
        } else if (pair < current->pair) {
            current = current->left;  //Continue searching left
        } else {
            current = current->right;  //Continue searching right
        }
    }

    return false;
}

//Get occurrence count of a pair
int AVLTree::getPairCount(const Pair& pair) {
    AVLNode* current = root;

    while (current != nullptr) {
        if (pair == current->pair) {
            return current->pair.getOccurrence();  //Return the occurrence count
        } else if (pair < current->pair) {
            current = current->left;  //same as search
        } else {
            current = current->right;  //same
        }
    }

    return 0;
}

//Get height of node
int AVLTree::getHeight(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }

    return node->height;
}

//Balance factor of node
int AVLTree::getBalance(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }

    return getHeight(node->left) - getHeight(node->right);  //Difference in height of left and right subtrees
}

//Left rotation around node to balance tree
AVLNode* AVLTree::rotateLeft(AVLNode* node) {
    AVLNode* pivot = node->right;
    AVLNode* subTree = pivot->left;

    pivot->left = node;
    node->right = subTree;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;  //Update height of rotated nodes
    pivot->height = max(getHeight(pivot->left), getHeight(pivot->right)) + 1;

    return pivot;  //Return the new root subtree
}

//Right rotation around a node to balance th tree
AVLNode* AVLTree::rotateRight(AVLNode* node) {
    AVLNode* pivot = node->left;
    AVLNode* subTree = pivot->right;

    pivot->right = node;
    node->left = subTree;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;  // Update height of rotated nodes
    pivot->height = max(getHeight(pivot->left), getHeight(pivot->right)) + 1;

    return pivot;  //same
}

// Balance node by performing rotations (if necessary)
AVLNode* AVLTree::balanceNode(AVLNode* node) {
    int balance = getBalance(node);

    if (balance > 1) {
        if (getBalance(node->left) < 0) {
            node->left = rotateLeft(node->left);  // Left-Right case,left rotation on the left child
        }
        return rotateRight(node);  //Left-Left case, right rotation on the node
    }

    if (balance < -1) {
        if (getBalance(node->right) > 0) {
            node->right = rotateRight(node->right);  //Right-Left case, right rotation on the right chid
        }
        return rotateLeft(node);  //Right-Right case, left rotation on the node
    }

    return node;  //Node is balanced, no rotations necessary
}

//Helper function, max value of an int
int AVLTree::max(int a, int b) {
    return (a > b) ? a : b;
}
