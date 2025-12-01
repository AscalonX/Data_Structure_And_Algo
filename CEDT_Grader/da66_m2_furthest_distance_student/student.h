#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <cmath>
#include "map_bst.h"

using namespace std;


template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &aux){

    if(!n) return 0;

    int a = 0;
    int b = 0;

    int temp = aux+1;
    a = my_recur(n->left,temp);
    b = my_recur(n->right,temp);

    return max(a,max(b,aux));
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {

    if(mSize == 0)return -1;
    if(mSize == 1) return 0;
    if(mSize == 2) return 1;
    if(mSize == 3) return 2;


	// write your code here
    int left = 0;
    int right = 0;
    int result_left = my_recur(mRoot->left,left);
    int result_right = my_recur(mRoot->right,right);

    // result_left = result_lefts;
    // result_right = result_right;
	return result_left + result_right + 2;
}

#endif
