#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,typename MappedT,typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  
  // 1. Create the result tree
  CP::map_bst<KeyT,MappedT,CompareT> result;
  
  // 2. Set up the "Hooks" (Pointers to Pointers)
  // 'child_L' points to the 'link' where we attach the next SMALL node
  node** child_L = &mRoot; 
  
  // 'child_R' points to the 'link' where we attach the next BIG node
  node** child_R = &result.mRoot;

  // We also need to track parents to update parent pointers later
  node* parent_L = NULL;
  node* parent_R = NULL;

  // 3. The Iterator (Start at root)
  node* it = mRoot;

  // 4. The Loop (O(h))
  while (it != NULL) {
      
      if (mLess(it->data.first, val)) {
          // CASE: Node is SMALLER than val.
          // It stays in the ORIGINAL tree (Left Side).
          
          *child_L = it;       // Attach node to the Left Hook
          it->parent = parent_L; // Update its parent
          
          parent_L = it;       // This node becomes the new parent for the next small node
          child_L = &(it->right); // Next small node will be attached to THIS node's right
          
          it = it->right;      // Move Right (to look for bigger numbers that might still be < val)
          
      } else {
          // CASE: Node is >= val.
          // It moves to the RESULT tree (Right Side).
          
          *child_R = it;       // Attach node to the Right Hook
          it->parent = parent_R; // Update its parent
          
          parent_R = it;       // This node becomes the new parent for the next big node
          child_R = &(it->left);  // Next big node will be attached to THIS node's left
          
          it = it->left;       // Move Left (to look for smaller numbers that might still be >= val)
      }
  }

  // 5. Close the lists (The last hooks point to NULL)
  *child_L = NULL;
  *child_R = NULL;

  // Note: The problem says we don't need to fix mSize, so we ignore it.
  return result;
}

#endif