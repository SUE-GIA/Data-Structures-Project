#include "UnorderedArray.h"
#include <iostream>

UnorderedArray::UnorderedArray() : pairs(nullptr), size(0), capacity(0) {}

UnorderedArray::~UnorderedArray()
{
    delete[] pairs;
}

// Add pair in the Unordered Array
void UnorderedArray::add(const Pair& newPair)
{
    //search if pair already exists and increment occurrence in this case
    for (int i = 0; i < size; i++)
    {
        if (pairs[i] == newPair)
        {
            pairs[i].incrementOccurrence();
            return;
        }
    }

    // Double the capacity of the Array when it gets full
    if (size == capacity)
    {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        Pair* newPairs = new Pair[newCapacity];

        for (int i = 0; i < size; i++)
        {
            newPairs[i] = pairs[i];
        }

        delete[] pairs;
        pairs = newPairs;
        capacity = newCapacity;
    }

    pairs[size] = newPair;
    size++;
}

//Search pair in the Unordered Array
bool UnorderedArray::search(const Pair& Pair) const
{
    for (int i = 0; i < size; i++)
    {
        if (pairs[i] == Pair)
        {
            return true;
        }
    }
    return false;
}

// Return number of occurrences of pair
int UnorderedArray::getPairCount(const Pair& pair) const
{
    if (search(pair))
    {
        return pair.getOccurrence();
    }
    return 0;
}

Pair UnorderedArray::getPair(int index) const
{
    return pairs[index];
}

int UnorderedArray::getSize() const
{
    return size;
}
