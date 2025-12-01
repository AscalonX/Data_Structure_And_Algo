#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <unordered_set>
#include <algorithm>
#include "queue.h"

using namespace std;


template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  unordered_set<size_t> s(pos.begin(),pos.end());

  // cout<<"--\n";

  // for(auto &it : s){
  //   cout<<it;
  // }
  // cout<<"===\n";
  vector<T> vec;

  int start_pos = mFront;
  // cout<<"\n";
  for(int i =1;i<=mSize;i++){  
    // cout<<"pos : "<<start_pos<<"i : "<<i;
    if(s.find(i-1) == s.end()){
      // cout<<"Not in remove start push back "<<mData[start_pos]<<"\n";
      vec.push_back(mData[start_pos]);
      // cout<<mData[start_pos]<<" ";
    }
    start_pos  = (mFront+i+mCap)%mCap;
  }
  // cout<<"\n";

  mFront = 0;

  for(int i = 0;i<vec.size();i++){
    mData[mFront+i] = vec[i];
  }
  mSize = vec.size();

}

#endif
