#include "HashTable.h"
#include <iostream>

HashTable::HashTable()
{
    capacity = 100000;
    size = 0;
    pairs = new Pair*[capacity];
    for (unsigned long int i=0;i<capacity;i++){
        pairs[i]=nullptr;
    }
}

HashTable::HashTable(unsigned long int capacity)
{
    this->capacity = capacity;
    size = 0;
    pairs = new Pair*[capacity];
    for (unsigned long int i=0;i<capacity;i++){
        pairs[i]=nullptr;
    }
}

HashTable::~HashTable()
{
    for (unsigned int i = 0; i < capacity; i++)
    {
        delete pairs[i];
    }
    delete[] pairs;
    pairs = nullptr;
    size=0;
    capacity=0;
}

//sums every character's ASCII number
unsigned long int HashTable::hash(const Pair& pair) const
{
    unsigned long int sum = 0;
    for (char c : pair.getFirst())
    {
        sum += static_cast<int>(c);
    }
    for (char c : pair.getSecond())
    {
        sum += static_cast<int>(c);
    }
    return (sum*17) % capacity;
}

// Double the capacity of the HashTable and rehash all the pairs
void HashTable::rehash()
{
    capacity *= 2;
    Pair **temp;
    temp = new Pair*[capacity];

    for (unsigned int i = 0; i < capacity; i++)
    {
        temp[i] = nullptr;
    }
    for (unsigned int i = 0; i < capacity / 2; i++)
    {
        if (pairs[i] != nullptr)
        {
            //std::cout << "time to rehash " << pairs[i] << std::endl;

            unsigned long int index = hash(*pairs[i]);

            while (temp[index] != nullptr)
            {
                index = (index + 1) % capacity;
            }
            temp[index] = pairs[i];
            pairs[i] = nullptr;
        }
    }


    delete[] pairs;
    pairs = temp;
}

// Add pair in the HashTable
void HashTable::add(const Pair& pair)
{
    if (size >= capacity * 0.5)
    {
        //std::cout<<"time to rehash "<<std::endl;
        // If the load factor exceeds 0.5, rehash the table
        rehash();
    }
    unsigned long int index = hash(pair);

    // Linear probing to find next available index or matching pair
    while (pairs[index]!=nullptr && *pairs[index] != pair)
    {
        index = (index + 1) % capacity;
    }

    if (pairs[index] != nullptr)
    {
        pairs[index]->incrementOccurrence(); //if matching pair found increment occurrences
        //std::cout<<"added: "<<pair<<"on index: "<<index<<std::endl;
        return;
    }
    else
    {
        pairs[index] = new Pair(pair);       //if an available index is found add the new pair
        //std::cout<<"added: "<<pair<<"on index: "<<index<<std::endl;
        size++;
        return;
    }
}

// Search pair in HashTable
bool HashTable::search(const Pair& pair) const
{
    unsigned long int index = hash(pair);

    // Linear probing to find next available index or matching pair
    while (pairs[index]!=nullptr && *pairs[index] != pair)
    {
        index = (index + 1) % capacity;
    }

    // if null pointer is found it means that the pair doesn't exist
    if (pairs[index] == nullptr)
    {
        return false;
    }

    return true;
}

// Return number of occurrences of pair
unsigned long int HashTable::getPairCount(const Pair& pair) const
{
    if (search(pair))
    {
        return pair.getOccurrence();
    }
    return 0;
}

unsigned long int HashTable::getSize() const
{
    return size;
}
