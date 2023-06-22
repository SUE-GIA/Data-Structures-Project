#ifndef UNORDEREDARRAY_H
#define UNORDEREDARRAY_H

#include "Pair.h"

class UnorderedArray
{
private:
    Pair* pairs;                                  // Pointer to the array of pairs
    int size;                                     // Current size of the array
    int capacity;                                 // Capacity of the array

public:
    UnorderedArray();                             // Constructor
    ~UnorderedArray();                            // Destructor
    void add(const Pair& newPair);                // Add a pair to the array
    bool search(const Pair& targetPair) const;    // Search for a pair in the array
    Pair getPair(int index) const;                // Get the pair at the specified index
    int getSize() const;                          // Get the current size of the array
    int getPairCount(const Pair& pair) const;     // Get the occurrence count of a pair in the array
};

#endif // UNORDEREDARRAY_H
