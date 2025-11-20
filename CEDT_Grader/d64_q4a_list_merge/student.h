#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {

  int n = 0;
  for(auto it = ls.begin(); it != ls.end(); it++) {
    CP::list<T> &l = *it;

    if(l.empty()) continue;

    n += l.size();

    //connect our tail to their head
    mHeader->prev->next = l.mHeader->next;
    l.mHeader->next->prev = mHeader->prev;

    
    //connect our head to their tail

    mHeader->prev = l.mHeader->prev;
    l.mHeader->prev->next = mHeader;

    l.mHeader->next = l.mHeader;
    l.mHeader->prev = l.mHeader;
    l.mSize = 0;
  }
  mSize += n;
}
#endif
