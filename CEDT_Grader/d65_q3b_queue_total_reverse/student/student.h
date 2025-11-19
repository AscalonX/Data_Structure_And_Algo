#include <iostream>
#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"
template <typename T>


void CP::queue<T>::reverse() {
  if(aux == 0 ){
    mFront = (mFront+mSize-1+mCap)%mCap;
    aux = 1;
  }
  else{
    mFront = (mFront+1-mSize +mCap)%mCap;
    aux = 0;
  }
}

template <typename T>
const T& CP::queue<T>::front() const {
  return mData[mFront];
}

template <typename T>
const T& CP::queue<T>::back() const {
  if(aux == 0){
    return mData[(mFront+mSize-1+mCap)%mCap];
  }
  else{
    return mData[(mFront+1-mSize+mCap)%mCap];
  }
}

template <typename T>
void CP::queue<T>::push(const T& element) {
  ensureCapacity(mSize+1);
  mData[(mFront + (aux?-mSize:mSize) +mCap) % mCap] = element;
  mSize++;
}

template <typename T>
void CP::queue<T>::pop() {
  if(aux == 0){
    mFront = (mFront+1+mCap)%mCap;
  }
  else{
    mFront = (mFront-1+mCap)%mCap;
  }
  mSize-=1;
}

#endif