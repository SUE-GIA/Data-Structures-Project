#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Pair.h"

class HashTable
{
private:
    Pair* *pairs;                                             // Array of pointers to Pair objects
    unsigned long int capacity;                               // Capacity of the hash table
    unsigned long int size;                                   // Current number of elements in the hash table

    unsigned long int hash(const Pair& pair) const;           // Hash function to calculate the index
    void rehash();                                            // Rehashes the table and increases the capacity

public:
    HashTable();                                              // Constructor
    HashTable(unsigned long int capacity);                    // Constructor
    ~HashTable();                                             // Destructor
    void add(const Pair& pair);                               // Adds a pair to the hash table
    bool search(const Pair& pair) const;                      // Searches for a pair in the hash table
    unsigned long int getPairCount(const Pair& pair) const;   // Gets the occurrence count of a pair in the hash table
    unsigned long int getSize() const;                        // Gets the current number of elements in the array
};

#endif // HASHTABLE_H
