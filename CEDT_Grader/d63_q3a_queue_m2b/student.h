#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  if(pos == mSize-1){
    return;
  }
  else{
    int temp = mData[(mFront+pos)%mCap];
    for(int i =pos+1;i<mSize;i++){
      mData[(mFront+i-1)%mCap] = mData[(mFront+i)%mCap];
    }
    mData[(mFront+mSize-1)%mCap] = temp;
  }
}

#endif
