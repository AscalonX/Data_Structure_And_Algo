#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  vector<int> temp;
  // pos.push_back(this->size());

  int curr = 0;
  for(int pos_n : pos){
    if(pos_n>curr){
      temp.insert(temp.end(),this->begin()+curr+1,this->begin()+pos_n-1);
    }
    else{
      curr = pos_n + 1;
    }
  }
  if(this->begin() +)
  this = temp;
}

#endif
