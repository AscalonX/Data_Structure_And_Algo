#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  size_t start_position = position-begin();
  size_t insert_size = last-first;

  ensureCapacity(mSize+insert_size);
  size_t oldSize = mSize;

  mSize = mSize + insert_size;

  for(int i =oldSize-1;i>=start_position;i--){
    mData[i+insert_size] = mData[i];

    if(i==0){
      break;
    }
  }

  for(int i =0;i<insert_size;i++){
    mData[start_position+i] = *first;
    first++;
  }
}

#endif
