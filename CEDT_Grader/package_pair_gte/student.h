#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T1,typename T2>
bool CP::pair<T1,T2>::operator>=(const pair<T1,T2>& other) const {
  //write your code here
  bool equal;
  bool morethan;
  if(this->first > other.first){
    morethan = true;
  }
  else if(this->first == other.first){
    if(this->second > other.second){
      morethan = true;
    }
    else{
      morethan = false;
    }
  }
  else{
    morethan = false;
  }

  if(this->first == other.first && this->second == other.second){
    equal = true;
  }
  else{
    equal = false;
  }

  if(equal || morethan){
    return true;
  }
  return false;
}

#endif
