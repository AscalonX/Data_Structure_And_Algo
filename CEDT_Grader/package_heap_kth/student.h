#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

using namespace std;

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {

  size_t to_check = min(mSize,10);

  vector<T> vec;
  for(int i =0;i<to_check;i++){
    vec.push_back(mData[i]);
  }

  sort(vec.begin(),vec.end(),mLess);

  return vec[k-1];
}

#endif