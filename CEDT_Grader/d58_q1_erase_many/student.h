#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  size_t slow = 0;
  size_t fast = 0;
  size_t pos_index = 0;

  for(int pos_index = 0;pos_index<pos.size();pos_index++){
      if(fast != pos[pos_index]){
        while(fast < mSize && fast != pos[pos_index]){
          mData[slow] = mData[fast];
          slow+=1;
          fast+=1;
        }
        fast+=1;
      }
      else{
        fast+=1;
      } 
  }

  while(fast < mSize){
    mData[slow] = mData[fast];
    slow+= 1;
    fast += 1;
  }
  
  mSize = slow;
}

#endif
