#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  //write your code here
  //can include anything
  std::vector<T> vec(mData, mData + mSize);

  // std::cout<<"-------\n";

  // for(auto x : vec){
  //   std::cout<<x<<" ";
  // }

  // std::cout<<"\n\n";
  auto greater_priority = [this](const T& a, const T& b) {
      return mLess(b, a); // true if 'a' has higher priority than 'b'
  };

  // 4. Use std::nth_element (O(N) average time)
  // This partially sorts the vector so that vec[k] is correct.
  std::nth_element(vec.begin(),    // Start
                     vec.begin() + k,  // The element we want
                     vec.end(),        // End
                     greater_priority  // The correct comparator
                    );

  // 5. Return vec[k] (0-indexed)
  return vec[k];
}

#endif
