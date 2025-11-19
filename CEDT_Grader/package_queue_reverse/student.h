#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>
#include <algorithm>

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
  while(a <= b){
    std::swap(mData[(mFront + a + mCap)%mCap],mData[(mFront + b + mCap)%mCap]);
    a+=1;
    b-=1;
  }
}

#endif
