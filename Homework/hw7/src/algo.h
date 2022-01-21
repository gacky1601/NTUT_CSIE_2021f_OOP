#pragma once
#include "pet.h"

template<typename ForwardIterator, typename Compare>
ForwardIterator maxPet(ForwardIterator first, ForwardIterator last, Compare comp) {
  ForwardIterator largest = first;
  while (first != last) {
    if (comp(*largest, *first)) {
      largest = first;
    }
    ++first;
  }
  return largest;
}
namespace pet_comp {
  bool largerWeight(Pet* p1, Pet* p2) {
    return p1->weight() < p2->weight();
  }
  bool longerName(Pet* p1, Pet* p2) {
    return p1->name().length() < p2->name().length();
  }
}

