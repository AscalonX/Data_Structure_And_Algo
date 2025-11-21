#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_set>


using namespace std;

unordered_set<int> s;


void recursive(int MAXI,int a){
    if(a >= MAXI){
        return;
    }
    s.insert(a);
    recursive(MAXI,a*2 + 1);
    recursive(MAXI,a*2 + 2);
}

int main(){
    int siz,pos;
    cin>>siz>>pos;

    recursive(siz,pos);
    cout<<siz-s.size()<<'\n';
    for(int i =0;i<siz;i++){
        if(s.find(i) == s.end()){
            cout<<i<<" ";
        }
    }
}