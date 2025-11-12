#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <unordered_set>
#include <algorithm>
//you can include any other file here
//you are allow to use any data structure

template <typename T>
void CP::vector<T>::uniq() {

  std::unordered_set<T> s;
  
  int write_idx = 0;


  for(int i = 0;i < mSize;i++){
    if(s.find(mData[i]) == s.end()){
      mData[write_idx] = mData[i];
      write_idx += 1;
      s.insert(mData[i]);
    }
  }

  mSize = write_idx;
}

#endif
