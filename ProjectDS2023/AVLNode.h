#ifndef AVLNODE_H
#define AVLNODE_H

#include "Pair.h"

class AVLNode {
public:
    Pair pair;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(const Pair& p) : pair(p), height(1), left(nullptr), right(nullptr) {}
};

#endif //AVLNODE_H
