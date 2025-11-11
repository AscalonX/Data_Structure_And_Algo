#include <iostream>
#include <string>

namespace CP{
    template <typename T>
    class vector{
        protected:
            T *mData;
            size_t mCap;
            size_t mSize;
            void expand(size_t capacity){
                T *arr = new T[capacity]();
                for(size_t i = 0;i<mSize ;i++){
                    arr[i] = mData[i];
                }

                delete [] mData;

                mData = arr;
                mCap = capacity;
            }

            void ensureCapacity(size_t capacity){
                if(capacity > mCap){
                    size_t s = (capacity > 2*mCap) ? capacity : 2*mCap;
                    expand(s);
                }
            }
            void rangeCheck(int n){
                if(n < 0 || (size_t)n >= mSize){
                    throw std::out_of_range("Index out of range");
                }
            }
        public:
            vector(){
                int cap = 1;
                mData = new T[cap]();
                mCap = cap;
                mSize = 0;
            }

            vector(size_t cap){
                mData = new T[cap]();
                mCap = cap;
                mSize = cap;
            }

            ~vector(){
                delete[] mData;
                std::cout<<"Delete mData";
            }

            void push_back(const T& element){
                ensureCapacity(mSize + 1);
                mData[mSize++] = element;
            }
            T& at(int index){
                rangecheck(index);
                return mData[index];
            }

            T& operator[](int index){
                return mData[index];
            }
    };
}

int main(){
    CP::vector<int> a(10);

    for(int x : a){
        std::cout<<x<<" ";
    }
}