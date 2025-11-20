
#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "map_bst.h"


template <typename KeyT,
          typename MappedT,
          typename CompareT>
typename CP::map_bst<KeyT,MappedT,CompareT>::iterator CP::map_bst<KeyT,MappedT,CompareT>::recursive(node* n,CP::map_bst<KeyT,MappedT,CompareT>::iterator p, CP::map_bst<KeyT,MappedT,CompareT>::iterator q) const
{   
    KeyT val_node = n->data.first;
    KeyT val_p = p->first;
    KeyT val_q = q->first;

    if(mLess(val_p,val_node) && mLess(val_q,val_node)) return recursive(n->left,p,q);
    else if(mLess(val_node,val_p)&&mLess(val_node,val_q)) return recursive(n->right,p,q);
    else{
        return iterator(n);
    }
}


template <typename KeyT,
          typename MappedT,
          typename CompareT>
typename CP::map_bst<KeyT,MappedT,CompareT>::iterator CP::map_bst<KeyT,MappedT,CompareT>::lca(CP::map_bst<KeyT,MappedT,CompareT>::iterator p, CP::map_bst<KeyT,MappedT,CompareT>::iterator q) const
{
    return recursive(mRoot,p,q);
}

#endif
