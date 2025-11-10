#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  int currect_pos = (mFront+pos)%mCap;

  for(int i=currect_pos+1;i<mSize;i++){
    size_t first_position = (i-1)%mCap;
    size_t second_position =(i)%mCap;
    std::swap(mData[first_position],mData[second_position]);
  }
}

#endif
