#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,typename MappedT,typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {

    CP::map_bst<KeyT,MappedT,CompareT> result;


    node **old_tree = &mRoot;
    node **new_tree = &result.mRoot;


    node *parent_l = NULL;
    node *parent_r = NULL;

    node *it = mRoot;


    while (it != NULL) {
      if (mLess(it->data.first, val)) {
          // CASE: Node belongs to LEFT (Original) tree.
          // 1. Attach 'it' to the current Left Hook.
          // 2. Fix 'it's parent pointer.
          // 3. Move the parent_L tracker to 'it'.
          // 4. Update child_L to point to the address of 'it->right' (the dangerous side).
          // 5. Move 'it' to the right.

          *old_tree = it;
          it->parent = parent_l;
          parent_l = it;

          old_tree = &(it->right);
          it = it->right;

      } else {
          // CASE: Node belongs to RIGHT (Result) tree.
          // 1. Attach 'it' to the current Right Hook.
          // 2. Fix 'it's parent pointer.
          // 3. Move the parent_R tracker to 'it'.
          // 4. Update child_R to point to the address of 'it->left' (the dangerous side).
          // 5. Move 'it' to the left.

          *new_tree = it;
          it->parent = parent_r;
          parent_r = it;

          new_tree = &(it->left);
          it = it->left;

      }
  }

  new_tree = NULL;
  old_tree = NULL;

  return result;
}

#endif