#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <unordered_set>
#include <algorithm>
//you can include any other file here
//you are allow to use any data structure


template <typename T>
void CP::vector<T>::uniq() {

  std::unordered_set<T> s;
  
  for(int i =0;i<mSize;i++){
    int curr = mData[i];

    if(s.find(curr) != s.end()){
      s.insert(curr);
    }
  }
  mSize = new_end - mData;
}

#endif
