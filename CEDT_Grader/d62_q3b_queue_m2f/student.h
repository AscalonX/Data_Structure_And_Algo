#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    for(int i = pos;i>0;i--){
        swap(mData[(mFront +i+mCap)%mCap],mData[(mFront + i-1+mCap)%mCap]);
    }
}

#endif
