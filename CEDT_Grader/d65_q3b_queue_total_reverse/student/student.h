#include <iostream>
#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"
template <typename T>
void CP::queue<T>::reverse() {
  std::cout<<"Curr ; "<<aux<<"\n";
  if(aux == -1){
    aux = 0;
  }
  else if(aux == 0){
    aux = -1;
  }
  std::cout<<"Curr ; "<<aux<<"\n";
  // Your code here
}

template <typename T>
const T& CP::queue<T>::front() const {
  // You MAY need to edit this function
  std::cout<<"AA : "<<aux<<" \n\n";
  if(aux == -1){
    std::cout<<"mfront : "<<mFront<<" Msize : "<<mSize<<" mCap : "<<mCap<<" Cal : "<<(mFront+mSize-1)%mCap<<"\n";

    return back();
  }
  else{
    return mData[mFront];
  }
}

template <typename T>
const T& CP::queue<T>::back() const {
  // You MAY need to edit this function
  if(aux == -1){
    return mData[(mFront-mSize-1)%mCap];
    // return mData[mFront];
  }
  else{
    return mData[(mFront + mSize - 1) % mCap];
  }
}

template <typename T>
void CP::queue<T>::push(const T& element) {
  // You MAY need to edit this function
  if(aux == -1){
    ensureCapacity(mSize + 1);
    mData[(mFront - mSize) % mCap] = element;
    mSize++;
  }
  else{
    ensureCapacity(mSize + 1);
    mData[(mFront + mSize) % mCap] = element;
    mSize++;
  }
}

template <typename T>
void CP::queue<T>::pop() {
  // You MAY need to edit this function
  if(aux == -1){
    mFront = (mFront-1) % mCap;
  }
  else{
    mFront = (mFront + 1) % mCap;
  }
  mSize--;
}

#endif