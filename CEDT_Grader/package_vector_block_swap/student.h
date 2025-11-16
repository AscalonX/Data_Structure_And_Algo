#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <iostream>

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  int a_idx = a-begin();
  int b_idx = b-begin();
  // std::cout<<a_idx<<" "<<b_idx<<" \n";
  // std::cout<<mSize<<"\n";
  // std::cout<<" M : "<<m<<"\n";
  if( (a_idx == b_idx ) || a_idx+m-1 >= mSize||a_idx<0 || b_idx<0 || b_idx+m-1 >= mSize ||a_idx+m-1 < 0 || b_idx+m-1 < 0|| m==0 || abs(a_idx-b_idx)<m){
    return false;
  }
  else{
    for(int i =0;i<m;i++){
      // swap(a*,b*);
      std::swap(mData[a_idx],mData[b_idx]);
      a_idx+=1;
      b_idx+=1;
      // a++;
      // b++;
    }
  }
  return true;
}

#endif
