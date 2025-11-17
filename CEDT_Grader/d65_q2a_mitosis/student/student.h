#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    int increase_size = abs(b-a)+1;

    T *beforeA  = new T[a]();
    T *appending = new T[increase_size]();


    for(int i =0 ;i<a;i++){
        beforeA[i] = top();
        pop();
    }
    for(int i =0;i<increase_size;i++){
        appending[i] = top();
        pop();
    }
    for(int i =increase_size-1;i>=0;i--){
        push(appending[i]);
        push(appending[i]);
    }
    for(int i =a-1;i>=0;i--){
        push(beforeA[i]);
    }
}

#endif