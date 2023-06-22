#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include "Pair.h"

class SortedArray {
private:
  Pair* pairs; //Pointer to array of pairs
  int size; //Current size of array
  int capacity; //Capacity of array

public:
  SortedArray();  ///Constructor
  ~SortedArray(); //Destructor
  void add(const Pair& newPair);  //Add a pair to array
  bool search(const Pair& targetPair) const; //Search for a pair in array
  Pair getPair(int index) const; //Get pair at specified index
  int getSize() const;  //Get current size of array
  int getPairCount(const Pair& pair) const; //Get occurrence count of a pair in array

private:
  bool isFull() const; //Check if the array is full
  int findInsertionIndex(const Pair& newPair) const; //Find the index to insert new pair
};

#endif //SORTEDARRAY_H
