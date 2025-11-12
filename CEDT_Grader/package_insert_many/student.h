#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <iostream>
#include <algorithm>


template <typename T>
// bool CP::vector<T>::cmp(const std::pair<int,T> &a,const std::pair<int,T> &b){
//   return a.first > b.first;
// }
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {

  std::sort(data.begin(),data.end());
  size_t padding_idx = 0;
  size_t read_idx    = 0;

  T *newmData = new T[mCap+data.size()]();

  for(int i =0;i<mSize+1;i++){
    // std::cout<<i<<" | "<<read_idx<<"\n";
    if(data[read_idx].first == i){
      // std::cout<<read_idx<<"\n";
      newmData[padding_idx+i] = data[read_idx].second;
      newmData[padding_idx+i+1] = mData[i];
      padding_idx+=1;
      read_idx+=1;
    }
    else if(i<mSize){
      newmData[padding_idx+i] = mData[i];
    }
  }
  mData = newmData;
  mSize = mCap+data.size();
}

#endif
