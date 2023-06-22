#include "SortedArray.h"

SortedArray::SortedArray() : pairs(nullptr), size(0), capacity(0) {}

SortedArray::~SortedArray() {
  delete[] pairs;
}

void SortedArray::add(const Pair& newPair) {
  int index = findInsertionIndex(newPair);

  //If the pair already exists, increment its occurrence
  if (index < size && pairs[index] == newPair) {
    pairs[index].incrementOccurrence();
  } else {
    if (size == capacity) {
      int newCapacity = (capacity == 0) ? 1 : capacity * 2;
      Pair* newPairs = new Pair[newCapacity];

      //Copy existing pairs
      for (int i = 0; i < size; i++) {
        newPairs[i] = pairs[i];
      }

      delete[] pairs;
      pairs = newPairs;
      capacity = newCapacity;
    }

    //Shift elements to make space for the new pair
    for (int i = size; i > index; i--) {
      pairs[i] = pairs[i - 1];
    }

    //Insert the new pair
    pairs[index] = newPair;
    size++;
  }
}

bool SortedArray::search(const Pair& targetPair) const {
  int left = 0; //Initialize the left pointer to the start of the array
  int right = size - 1; //Initialize the right pointer to the end of the array

  while (left <= right) { // Perform binary search until the left and right pointers meet
    int mid = (left + right) / 2;

    if (pairs[mid] == targetPair) {
      return true;
    } else if (pairs[mid] < targetPair) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return false; //TargetPair not found
}

Pair SortedArray::getPair(int index) const {
  return pairs[index]; //Return the pair at the specified index
}

int SortedArray::getSize() const {
  return size; //Return size
}

int SortedArray::getPairCount(const Pair& pair) const {
  int pairCount = 0; //Initialize the occurrence count of the pair

  for (int i = 0; i < size; i++) {
    if (pairs[i] == pair) {
      pairCount += pairs[i].getOccurrence(); //Increment the occurrence count by the occurrence of the pair at index i
    }
  }

  return pairCount; //Return the total occurrence count of the pair
}

int SortedArray::findInsertionIndex(const Pair& newPair) const {
  int left = 0; //same as search
  int right = size - 1; //same

  while (left <= right) { //same binary search
    int mid = (left + right) / 2; //Calculate the middle index

    if (pairs[mid] == newPair) {
      return mid;
    } else if (pairs[mid] < newPair) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return left;
}
