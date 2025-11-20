#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <algorithm>

using namespace std;

template <typename T,typename Comp>
size_t CP::priority_queue<T,Comp>::get_rank(size_t pos) const {

  T target = mData[pos];
  
  size_t count = 0;

  // 2. Iterate through the entire heap to find elements strictly larger than target
  for (size_t i = 0; i < mSize; i++) {
    // In a standard priority queue (Max Heap), mLess(a, b) means a < b.
    // We want to count elements where target < mData[i].
    if (mLess(target, mData[i])) {
      count++;
    }
  }

  return count;

  // return pos-dis;;
}

#endif
