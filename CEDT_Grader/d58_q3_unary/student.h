#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* ptr) const {

  if(!ptr) return 0;
  if(!ptr->left && !ptr->right){
    return 0;
  }
  int a = 0;
  int b = 0;
  int c = 0;

  if(!ptr->left || !ptr->right){
    c = 1;
  }
  a = process(ptr->left);
  b = process(ptr->right);
  return c + a +b;
  // return 0;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::count_unary() const {
  //write your code here
  if(mSize == 0) return 0;
  return process(mRoot);
  // return 0;
}

#endif
