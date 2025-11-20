#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,typename MappedT,typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  node *trav = mRoot;

  whlie(trav != NULL && trav->data.first < val){
    trav = trav->right;
  }

  CP::map_bst<KeyT,MappedT,CompareT> result;


  result = trav->right;
  result->parent = NULL;

  trav->right = NULL;

  return result;
}

#endif